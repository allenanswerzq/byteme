/* created   : 2020-08-16 09:24:58
 * accepted  : 2020-08-16 11:22:58
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

// @Solution: Segment tree + Difference

struct Node {
  ll gcd = 0;
  ll val = 0;

  // NOTE: each Node denotes an interval [l, r).
  void apply(int l, int r, ll v) {
    // trace(l, r, v);
    val += v;
    gcd += v;
  }

  static Node combine(const Node& a, const Node& b) {
    Node ans;
    ans.gcd = __gcd(a.gcd, b.gcd);
    ans.val = a.val + b.val;
    return ans;
  }

  static void push_down(vector<Node>& tree, int x, int l, int r) {
  }

  static void pull_up(vector<Node>& tree, int x) {
    tree[x] = combine(tree[x << 1], tree[x << 1 | 1]);
  }
};

// Zero-indexed segment tree
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

  template <typename M>
  void build(int x, int l, int r, const vector<M>& v) {
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
  template <typename M>
  void modify(int x, int l, int r, int lx, int rx, const M& v) {
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


// 1 3 5 7 9
// _________
// 2 4 6 8 10
// __________
// 2 4 12 8 10
//   ______
void solve() {
  int n, m; cin >> n >> m;
  vector<ll> a(n + 1);
  vector<ll> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i] - a[i - 1];
  }
  // trace(a, b);
  trace(n, m);
  Segtree<Node> seg(b);
  for (int i = 0; i < m; i++) {
    char op; cin >> op;
    if (op == 'Q') {
      ll x, y; cin >> x >> y;
      // for (int j = 1; j <= n; j++) {
      //   trace(j, a[j], seg.query(1, j + 1).val);
      // }
      ll ax = seg.query(1, x + 1).val;
      cout << __gcd(ax, abs(seg.query(x + 1, y + 1).gcd)) << "\n";
    }
    else {
      ll x, y, d; cin >> x >> y >> d;
      seg.modify(x, x + 1, d);
      if (y + 1 <= n) {
        seg.modify(y + 1, y + 2, -d);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
