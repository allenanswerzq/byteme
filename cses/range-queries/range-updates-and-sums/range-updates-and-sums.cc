/* created   : 2020-11-29 21:57:31
 * accepted  : 2020-12-01 22:22:22
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;


template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct LazySegtree {
 public:
  explicit LazySegtree(int n) : LazySegtree(std::vector<S>(n, e())) {}

  explicit LazySegtree(const std::vector<S>& v) : n_(int(v.size())) {
    log = ceil_pow2(n_);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    lz = std::vector<F>(size, id());
    for (int i = 0; i < n_; i++) {
      d[size + i] = v[i];
    }
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void debug() {
    for (int i = 1; i <= log + 1; i++) {
      int p = (1 << (i - 1));
      int l = (1 << (i - 1));
      vector<S> tmp;
      for (int j = 0; j < l; j++) {
        tmp.push_back(d[p + j]);
      }
      trace(tmp);
      (void)tmp;
    }

  }
  int ceil_pow2(int x) {
    int t = 1, c = 0;
    while (t < x) {
      t <<= 1;
      c++;
    }
    return c;
  }

  void set(int p, S x) {
    assert(0 <= p && p < n_);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < n_);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n_);
    if (l == r) return e();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push(r >> i);
    }

    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }

    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    assert(0 <= p && p < n_);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= n_);
    if (l == r) return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, f);
        if (r & 1) all_apply(--r, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

 private:
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size) {
      lz[k] = composition(f, lz[k]);
    }
  }

  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }

  int n_, size, log;
  std::vector<S> d;
  std::vector<F> lz;
};

struct S {
  ll sum;
  ll size;
};

ostream& operator<<(ostream& os, const S& s) {
  return os << "(" << s.sum << " " << s.size << ")";
}

S op(S a, S b) { return S{a.sum + b.sum, a.size + b.size}; }
S e() { return S{0, 0}; }

struct F {
  ll inc;
  ll set;
  bool set_vaild;
};

S mapping(F f, S s) {
  if (f.set_vaild) {
    s.sum = s.size * f.set;
  }
  s.sum += f.inc * s.size;
  return s;
}

F id() { return {0, 0, 0}; }
F composition(F parent, F child) {
  if (parent.set_vaild) {
    child.set_vaild = true;
    child.set = parent.set;
    child.inc = parent.inc;
  }
  else {
    child.inc += parent.inc;
  }
  return child;
}

void solve() {
  int N, Q; cin >> N >> Q;
  LazySegtree<S, op, e, F, mapping, composition, id> seg(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    seg.set(i, S{x, 1});
  }
  seg.debug();
  for (int i = 0; i < Q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int a, b, x; cin >> a >> b >> x;
      a--, b--;
      seg.apply(a, b + 1, F{x, 0, 0});
    }
    else if (op == 2) {
      int a, b, x; cin >> a >> b >> x;
      a--, b--;
      seg.apply(a, b + 1, F{0, x, 1});
    }
    else {
      int a, b; cin >> a >> b;
      a--, b--;
      trace(a, b);
      cout << seg.prod(a, b + 1).sum << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
