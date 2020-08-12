/* created   : 2020-08-11 20:01:46
 * accepted  : 2020-08-12 22:35:36
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

// Zero-indexed segment tree
class Segtree {
public:
  struct Node {
    int lmax = 0;
    int rmax = 0;
    int sum = 0;
    int ans = 0;

    // NOTE: each Node denotes an interval [l, r).
    void apply(int l, int r, int v) {
      lmax = rmax = sum = ans = v;
    }
  };

  Node combine(const Node& a, const Node& b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.lmax = max(a.lmax, a.sum + b.lmax);
    res.rmax = max(b.rmax, b.sum + a.rmax);
    res.ans = max({a.ans, b.ans, a.rmax + b.lmax});
    return res;
  }

  void push_down(int x, int l, int r) {
  }

  void pull_up(int x) {
    tree[x] = combine(tree[x << 1], tree[x << 1 | 1]);
  }

  int n;
  vector<Node> tree;

  void build(int x, int l, int r) {
    if (l + 1 == r) {
      return;
    }
    int y = l + (r - l) / 2;
    build(x << 1, l, y);
    build(x << 1 | 1, y, r);
    pull_up(x);
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
    pull_up(x);
  }

  Node query(int x, int l, int r, int lx, int rx) {
    if (rx <= l || r <= lx) {
      return Node{};
    }
    if (lx <= l && r <= rx) {
      return tree[x];
    }
    push_down(x, l, r);
    int y = l + (r - l) / 2;
    Node left = query(x << 1, l, y, lx, rx);
    Node right = query(x << 1 | 1, y, r, lx, rx);
    Node res = combine(left, right);
    pull_up(x);
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
    push_down(x, l, r);
    if (lx < y) {
      // Partial cover left child.
      //        [lx______rx)
      //  (x)[l_______y_______r)
      modify(x << 1, l, y, lx, rx, v);
    }
    if (rx > y) {
      // Partial cover right child.
      //     [lx_______________rx)
      //          [l________y________r)
      modify(x << 1 | 1, y, r, lx, rx, v);
    }
    pull_up(x);
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
  Segtree(const vector<M>& v) {
    n = big((int) v.size());
    tree.resize(2 * n);
    vector<M> t = v;
    t.resize(n);
    build(1, 0, n, t);
  }

  Node query(int lx, int rx) {
    assert(0 <= lx && lx < rx && rx <= n);
    return query(1, 0, n, lx, rx);
  }

  template <typename M>
  void modify(int lx, int rx, const M& v) {
    assert(0 <= lx && lx < rx && rx <= n);
    modify(1, 0, n, lx, rx, v);
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Segtree seg(a);
  for (int i = 0; i < m; i++) {
    int k, x, y; cin >> k >> x >> y;
    if (k == 1) {
      x--, y--;
      if (x > y) swap(x, y);
      cout << seg.query(x, y + 1).ans << "\n";
    }
    else {
      x--;
      seg.modify(x, x + 1, y);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
