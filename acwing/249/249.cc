/* created   : 2020-08-16 20:33:46
 * accepted  : 2020-08-16 20:33:54
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

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

  template <typename U, typename... Args>
  void build(int x, int l, int r, const vector<U>& v, Args&&... args) {
    if (l + 1 == r) {
      assert(0 <= l && l < (int) v.size());
      tree[x].apply(l, r, v[l], std::forward<Args>(args)...);
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
  template <typename U, typename... Args>
  void modify(int x, int l, int r, int lx, int rx, const U& v, Args&&... args) {
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
      tree[x].apply(l, r, v, std::forward<Args>(args)...);
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

  template <typename U>
  Segtree(vector<U>& v) : n(big(v.size())) {
    tree.resize(2 * n);
    v.resize(n);
    build(1, 0, n, v);
  }

  T query(int lx, int rx) {
    assert(0 <= lx && lx < rx && rx <= n);
    return query(1, 0, n, lx, rx);
  }

  template <typename U, typename... Args>
  void modify(int lx, int rx, const U& v, Args&&... args) {
    assert(0 <= lx && lx < rx && rx <= n);
    modify(1, 0, n, lx, rx, v, std::forward<Args>(args)...);
  }
};

// Discrete
struct Discreter {
  vector<double> e;
  unordered_map<double, int> t;
  int mx = 0;

  Discreter(vector<double>& v) {
    e = v;
    sort(all(e));
    e.erase(unique(all(e)), e.end());
    for (const auto& x : v) {
      int p = upper_bound(all(e), x) - e.begin();
      mx = max(mx, p);
      t[x] = p
    }
  }

  int get_max() { return mx; }

  // Given a raw value, returns the discreted value.
  int get_dis(double x) { return t[x]; }

  // Given a discreted value, return the raw value.
  int get_raw(int x) { return e[x]; }
};

struct SegNode {
  int cnt = 0;
  double len = 0;

  // NOTE: each SegNode denotes an interval [l, r).
  void apply(int l, int r, int v, const Discreter& dis) {
    cnt += v;
    if (cnt > 0) {
      len = dis.get_raw(r) - dis.get_raw(l);
    }
  }

  static SegNode combine(const SegNode& a, const SegNode& b) {
    SegNode ans;
    ans.cnt = a.cnt + b.cnt;
    return ans;
  }

  static void push_down(vector<SegNode>& tree, int x, int l, int r) {
  }

  static void pull_up(vector<SegNode>& tree, int x) {
    if (tree.cnt > 0) {
      tree.len =
    }
    tree[x] = combine(tree[x << 1], tree[x << 1 | 1]);
  }
};

void solve(int n, int tc) {
  array<double, 4> pos(n);
  vector<double> v;
  for (int i = 0; i < n; i++) {
    double y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    pos.push_back({x1, y1, y2, 1});
    pos.push_back({x1, y1, y2, -1});
    v.push_back(y1);
    v.push_back(y2);
  }
  sort(all(pos));
  Discreter dis(v);
  int mx = dis.get_max();
  Segtree<SegNode> seg(dis.get_max());
  double x = 0;
  double ans = 0;
  for (const auto& p : pos) {
    ans += (p[0] - x) * seg.query(0, mx);
    int y1 = dis.get_dis(p[1]);
    int y2 = dis.get_dis(p[2]);
    seg.modify(y1, y2, (int) p[3], dis);
    x = p[0];
  }
  cout << "Total explored area: " << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << set_precision(2);
  int n;
  int tc = 0;
  while (cin >> n && n) {
    cout << "Test case #" << ++tc << "\n";
    solve(n);
  }
  return 0;
}
