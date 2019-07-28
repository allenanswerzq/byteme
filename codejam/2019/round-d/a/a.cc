/*
 * created   : 2019-07-28 13:09:11
 * accepted  : 2019-07-28 15:47:04
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

class segtree {
public:
  struct node {
    int sum = 0;

    // Each node denotes an interval [l, r).
    void apply(int l, int r, int v) {
      sum = v;
    }

    friend ostream& operator<<(ostream& os, node& a) {
      os << "node(" << a.sum << ")";
      return os;
    }
  };

  node unite(const node& a, const node& b) {
    node res;
    res.sum = a.sum ^ b.sum;
    return res;
  }

  void push(int x, int l, int r) {

  }

  void pull(int x) {
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
    pull(x);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M>& v) {
    if (l + 1 == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = l + (r - l) / 2;
    build(x << 1, l, y, v);
    build(x << 1 | 1, y, r, v);
    pull(x);
  }

  node get(int x, int l, int r, int lx, int rx) {
    if (rx <= l || r <= lx) {
      return node{};
    }
    if (lx <= l && r <= rx) {
      return tree[x];
    }
    push(x, l, r);
    int y = l + (r - l) / 2;
    node res = unite(get(x << 1, l, y, lx, rx), get(x << 1 | 1, y, r, lx, rx));
    pull(x);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int lx, int rx, const M&... v) {
    if (rx <= l || r <= lx) {
      return;
    }
    if (lx <= l && r <= rx) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = l + (r - l) / 2;
    push(x, l, r);
    if (lx < y) {
      modify(x << 1, l, y, lx, rx, v...);
    }
    if (rx > y) {
      modify(x << 1 | 1, y, r, lx, rx, v...);
    }
    pull(x);
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    int t = 1;
    while (t < n) {
      t <<= 1;
    }
    n = t;
    tree.resize(2 * n);
    build(1, 0, n);
  }

  template <typename M>
  segtree(const vector<M>& v) {
    n = v.size();
    int t = 1;
    while (t < n) {
      t <<= 1;
    }
    n = t;
    tree.resize(2 * n);
    vector<M> a = v;
    a.resize(n);
    build(1, 0, n, a);
  }

  node get(int lx, int rx) {
    assert(0 <= lx && lx <= rx && rx <= n);
    return get(1, 0, n, lx, rx);
  }

  node get(int p) {
    assert(0 <= p && p <= n);
    return get(1, 0, n, p, p + 1);
  }

  template <typename... M>
  void modify(int lx, int rx, const M&... v) {
    assert(0 <= lx && lx <= rx && rx <= n);
    modify(1, 0, n, lx, rx, v...);
  }
};

void solve(int tc) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << "Case #" << tc << ": ";
  segtree seg(a);
  auto check = [&](int md) {
    for (int i = 0; i + md <= n; i++) {
      int x = seg.get(i, i + md).sum;
      // trace(md, i, i + md, n, x);
      if (__builtin_popcount(x) % 2 == 0) {
        return true;
      }
    }
    return false;
  };
  // q * n * log(n)
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    seg.modify(x, x + 1, y);
    int ans = 0;
    for (int md = n; i >= 0; md--) {
      if (check(md)) {
        ans = md;
        break;
      }
    }
    if (i > 0) {
      cout << " ";
    }
    cout << ans;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }
  return 0;
}
