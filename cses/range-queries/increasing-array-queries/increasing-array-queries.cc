/* created   : 2021-03-13 11:20:38
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

struct Segtree {
  struct node {
    // Compute range or interval sum
    ll sum = 0;
    ll lazy = 0;

    void apply(int l, int r, ll val) {
      sum += (r - l) * val;
      lazy += val;
    }

    string debug_string() {
      ostringstream oss;
      oss << sum << "," << lazy;
      return oss.str();
    }
  };

  node unite(const node& a, const node& b) const {
    return node{a.sum + b.sum, 0};
  }

  inline void push_down(int x, int l, int r) {
    int y = l + (r - l) / 2;
    tree[x << 1].apply(l, y, tree[x].lazy);
    tree[x << 1 | 1].apply(y, r, tree[x].lazy);
    tree[x].lazy = 0;
  }

  inline void pull_up(int x) {
    tree[x] = unite(tree[x << 1], tree[x << 1 | 1]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l + 1 == r) {
      return;
    }
    int y = l + (r - l) / 2;
    build(x << 1, l, y);
    build(x << 1 | 1, y, r);
    pull_up(x);
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
    pull_up(x);
  }

  node query_impl(int x, int l, int r, int lx, int rx) {
    if (rx <= l || r <= lx) {
      //          l-------r
      // lx----rx           lx-----rx
      // NOTE: here returns the default value for a node
      return node{};
    }
    if (lx <= l && r <= rx) {
      return tree[x];
    }
    push_down(x, l, r);
    int y = l + (r - l) / 2;
    node left = query_impl(x << 1, l, y, lx, rx);
    node right = query_impl(x << 1 | 1, y, r, lx, rx);
    node res = unite(left, right);
    pull_up(x);
    return res;
  }

  void debug_impl(int x, int l, int r, int lx, int rx, int level = 1) {
    if (rx <= l || r <= lx) {
      return;
    }
    if (l + 1 < r) {
      push_down(x, l, r);
    }
    if (lx <= l && r <= rx) {
      cerr << string(level, ' ')
           << l << "->" << r << " ("
           << tree[x].debug_string()
           << ")\n";
    }
    if (l + 1 < r) {
      int y = l + (r - l) / 2;
      debug_impl(x << 1, l, y, lx, rx, 2 * level);
      debug_impl(x << 1 | 1, y, r, lx, rx, 2 * level);
      pull_up(x);
    }
  }

  template <typename ...U>
  void modify_impl(int x, int l, int r, int lx, int rx, const U&... v) {
    if (rx <= l || r <= lx) {
      return;
    }
    if (lx <= l && r <= rx) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = l + (r - l) / 2;
    push_down(x, l, r);
    if (lx < y) {
      modify_impl(x << 1, l, y, lx, rx, v...);
    }
    if (rx > y) {
      modify_impl(x << 1 | 1, y, r, lx, rx, v...);
    }
    pull_up(x);
  }

  int ceil_pow2(int x) {
    int t = 1;
    while (t < x) {
      t <<= 1;
    }
    return t;
  }

  Segtree(int n_) : n(ceil_pow2(n_)) {
    tree.resize(2 * n);
    build(1, 0, n);
  }

  template <typename M>
  Segtree(vector<M>& v) : n(ceil_pow2(v.size())) {
    tree.resize(2 * n);
    v.resize(n);
    build(1, 0, n, v);
  }

  node query(int lx, int rx) {
    assert(0 <= lx && lx <= rx && rx <= n);
    return query_impl(1, 0, n, lx, rx);
  }

  template <typename ...M>
  void modify(int lx, int rx, const M&... v) {
    assert(0 <= lx && lx <= rx && rx <= n);
    modify_impl(1, 0, n, lx, rx, v...);
  }

  void debug() {
#ifdef LOCAL
    debug_impl(1, 0, n, 0, n);
#endif
  }
};

void solve() {
  int N, Q; cin >> N >> Q;
  //   _______|
  //  |       |
  //  |       |
  //  i       j
  // Find the next value greater than A[i], add A[i] to interval [i, j)
  // which will be the A[i]'s contribution to the answer
  Segtree seg(N);
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    A[i] = x;
    // NOTE: set the original value so that it evens out later.
    seg.modify(i, i + 1, -x);
  }
  seg.debug();
  vector<vector<array<int, 2>>> queries(N);
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    a--;
    queries[a].push_back({b, i});
  }
  vector<int> stk;
  stk.push_back(N);
  vector<ll> ans(Q);
  for (int i = N - 1; i >= 0; i--) {
    // Decreasing stack
    while (stk.back() < N && A[i] >= A[stk.back()]) {
      int n = (int) stk.size();
      seg.modify(stk[n - 1], stk[n - 2], -A[stk[n - 1]]);
      stk.pop_back();
    }
    seg.modify(i, stk.back(), A[i]);
    stk.push_back(i);
    for (auto& [r, idx] : queries[i]) {
      ans[idx] = seg.query(i, r).sum;
    }
  }
  for (auto a : ans) {
    cout << a << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
