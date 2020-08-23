/* created   : 2020-08-22 06:58:02
 * accepted  : 2020-08-22 07:48:45
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

// @Solution: Sweep line + Segment tree(Lazy)

template <typename T>
struct Segtree {
  int n;
  vector<T> tree;

  void build(int x, int l, int r) {
    if (l + 1 == r) {
      return;
    }
    int y = l + (r - l) / 2;
    build(x << 1, l, y);
    build(x << 1 | 1, y, r);
    T::pull_up(tree, x);
  }

  template <typename U>
  void build(int x, int l, int r, const vector<U>& v) {
    if (l + 1 == r) {
      assert(0 <= l && l < (int) v.size());
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = l + (r - l) / 2;
    build(x << 1, l, y, v);
    build(x << 1 | 1, y, r, v);
    T::pull_up(tree, x);
  }

  T query(int x, int l, int r, int lx, int rx) {
    if (rx <= l || r <= lx) {
      return T{};
    }
    if (lx <= l && r <= rx) {
      return tree[x];
    }
    T::push_down(tree, x, l, r);
    int y = l + (r - l) / 2;
    T left = query(x << 1, l, y, lx, rx);
    T right = query(x << 1 | 1, y, r, lx, rx);
    T res = T::combine(left, right);
    T::pull_up(tree, x);
    return res;
  }

  // NOTE: [lx, rx) denotes the interval need to be modified.
  template <typename U>
  void modify(int x, int l, int r, int lx, int rx, const U& v) {
    if (rx <= l || r <= lx) {
      // No cover at all.
      // [lx, rx)  [l ... r)  [lx, rx)
      // ___________________
      //         ____________________
      return;
    }
    if (lx <= l && r <= rx) {
      // Full cover.
      // [lx_________________rx)
      //     (x)[l------r)
      tree[x].apply(l, r, v);
      return;
    }
    int y = l + (r - l) / 2;
    T::push_down(tree, x, l, r);
    if (lx < y) {
      // Partial cover left child.
      //        [lx______rx)
      //  (x)[l_______y_______r)
      modify(x << 1, l, y, lx, rx, v);
    }
    if (rx > y) {
      // Partial cover right child.
      //     [lx_______________rx)
      //          (x)[l________y________r)
      modify(x << 1 | 1, y, r, lx, rx, v);
    }
    T::pull_up(tree, x);
  }

  int big(int x) {
    int t = 1;
    while (t < x) {
      t <<= 1;
    }
    return t;
  }

  Segtree(int n_) : n(big(n_)) {
    tree.resize(2 * n);
    build(1, 0, n);
  }

  template <typename M>
  Segtree(vector<M>& v) : n(big(v.size())) {
    tree.resize(2 * n);
    v.resize(n);
    build(1, 0, n, v);
  }

  T query(int lx, int rx) {
    assert(0 <= lx && lx < rx && rx <= n);
    return query(1, 0, n, lx, rx);
  }

  template <typename M>
  void modify(int lx, int rx, const M& v) {
    assert(0 <= lx && lx < rx && rx <= n);
    modify(1, 0, n, lx, rx, v);
  }
};

struct Node {
  ll mx = 0;
  ll add = 0;

  // NOTE: each Node denotes an interval [l, r).
  void apply(int l, int r, int v) {
    add += v;
    mx += v;
    // trace(l, r, v, add, mx);
  }

  static Node combine(const Node& a, const Node& b) {
    Node ans;
    ans.mx = max(a.mx, b.mx);
    return ans;
  }

  static void push_down(vector<Node>& tree, int x, int l, int r) {
    if (tree[x].add) {
      tree[x << 1].mx += tree[x].add;
      tree[x << 1].add += tree[x].add;
      tree[x << 1 | 1].mx += tree[x].add;
      tree[x << 1 | 1].add += tree[x].add;
      tree[x].add = 0;
    }
  }

  static void pull_up(vector<Node>& tree, int x) {
    tree[x] = combine(tree[x << 1], tree[x << 1 | 1]);
  }
};

void solve() {
  // _____
  //    ______
  int n, w, h;
  while (cin >> n >> w >> h) {
    vector<array<ll, 4>> a(2 * n);
    vector<int> e;
    for (int i = 0; i < n; i++) {
      ll x, y, c; cin >> x >> y >> c;
      a[i]     = {x, y, y + h - 1, c};
      a[i + n] = {x + w, y, y + h - 1, -c};
      e.push_back(y);
      e.push_back(y + h - 1);
    }
    sort(all(e));
    e.erase(unique(all(e)), e.end());
    for (int i = 0; i < 2 * n; i++) {
      a[i][1] = lower_bound(all(e), a[i][1]) - e.begin();
      a[i][2] = lower_bound(all(e), a[i][2]) - e.begin();
    }
    sort(all(a));
    trace(e, a);
    int m = e.size();  // discreted max y coordinate
    Segtree<Node> seg(m);
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++) {
      seg.modify(a[i][1], a[i][2], a[i][3]);
      trace(a[i][1], a[i][2], a[i][3], m, seg.query(0, m).mx);
      ans = max(ans, seg.query(0, m).mx);
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
