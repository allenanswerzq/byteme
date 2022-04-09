/* created   : 2020-11-13 15:51:53
 * accepted  : 2020-11-13 16:21:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int inv(int a, int mod) {
  a %= mod;
  assert(a);
  return a == 1 ? 1 : int(mod - ll(inv(mod, a)) * ll(mod) / a);
}

int mul(int a, int b) { return (int)((ll)a * b % mod); }

void solve() {
  int N; cin >> N;
  int s = N * (N + 1) / 2;
  if (s % 2) {
    cout << "0\n";
    return;
  }
  s /= 2;
  // 1 2 3 4 5 6 7
  // The number of ways to get the sum `s` using the first `i` numbers.
  // f[i][s] = f[i - 1][s] + f[i - 1][s - ai]
  vector<int> f(s + 1);
  f[0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = s; j >= 0; j--) {
      if (j >= i) {
        add(f[j], f[j - i]);
      }
    }
  }
  trace(s, f);
  // f[s] / 2
  cout << mul(f[s], inv(2, mod)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
