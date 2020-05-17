/* created   : 2020-05-17 18:10:25
 * accepted  : 2020-05-17 22:24:57
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

template <int N>
bitset<N> sieve() {
  bitset<N> bs;
  bs.set();
  bs[0] = 0;
  bs[1] = 0;
  for (int i = 2; i < N; i++) {
    if (bs.test(i)) {
      for (int j = i + i; j < N; j += i) {
        bs.reset(j);
      }
    }
  }
  return bs;
}

bool check(int x) {
  string s = to_string(x);
  int lo = 0, hi = (int) s.size() - 1;
  while (lo <= hi) {
    if (s[lo] != s[hi]) {
      return false;
    }
    lo++, hi--;
  }
  return true;
}

void solve() {
  int p, q; cin >> p >> q;
  const int N = 1e7;
  auto bs = sieve<N>();
  vector<ll> ps(N);
  for (int i = 1; i + 1 < N; i++) {
    ps[i + 1] = ps[i] + bs[i];
  }
  vector<int> pa(N);
  for (int i = 1; i + 1 < N; i++) {
    pa[i + 1] = pa[i] + check(i);
  }
  // trace(ps, pa);
  for (int i = N - 1; i >= 1; i--) {
    if (ps[i] * q <= pa[i] * p) {
      cout << i - 1 << "\n";
      return;
    }
  }
  cout << "Palindromic tree is better than splay tree\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
