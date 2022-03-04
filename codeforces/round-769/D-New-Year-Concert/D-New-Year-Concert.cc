/* created   : 2022-03-02 07:17:25
 * accepted  : 2022-03-04 22:19:37
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}

struct Segtree {
  Segtree(const std::vector<int> &v) : n(int(v.size())) {
    log = ceil_pow2(n);
    size = 1 << log;
    d = std::vector<int>(2 * size);
    for (int i = 0; i < n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, int x) {
    assert(0 <= p && p < n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  int get(int p) {
    assert(0 <= p && p < n);
    return d[p + size];
  }
  // [l, r)
  int prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    l += size;
    r += size;
    int sml = d[l], smr = d[r - 1];
    while (l < r) {
      if (l & 1) sml = __gcd(sml, d[l++]);
      if (r & 1) smr = __gcd(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return __gcd(sml, smr);
  }

  int all_prod() { return d[1]; }

  int n, size, log;
  std::vector<int> d;

  void update(int k) { d[k] = __gcd(d[2 * k], d[2 * k + 1]); }
};

void solve() {
  // gcd(l, gcd(l+1, r)) = r-l+1
  //
  // if gcd(l, r) = r - l + 1, then gcd for any segments inside [l, r]
  // must greater >= r - l + 1, becasue gcd not incresing with more numbers
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  Segtree seg(A);
  //     1
  //   1   2
  //  1 4 2 0
  // trace(seg.d, seg.prod(1, 3));
  vector<ar> pos;
  for (int i = 0; i < N; i++) {
    // [i...md....]
    int lo = i;
    int hi = N + 1;
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      // [lo, md)
      if (seg.prod(i, md) >= md - i) {
        lo = md;
      } else {
        hi = md;
      }
    }
    // trace(i, lo, seg.prod(i, lo));
    if (i < lo && lo < N + 1 && seg.prod(i, lo) == lo - i) {
      pos.push_back({i, lo - 1});
    }
  }
  trace(pos);
  // l   r
  // |___|
  //  |----|
  //    |----|
  //       |-------|
  vector<int> f(N);
  int m = pos.size();
  for (int i = 0; i < m;) {
    f[pos[i][1]] = 1;
    int j = i + 1;
    while (j < m && pos[j][0] <= pos[i][1]) {
      j++;
    }
    i = j;
  }
  trace(f);
  for (int i = 1; i < N; i++) {
    f[i] += f[i - 1];
  }
  for (int i = 0; i < N; i++) {
    cout << f[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
