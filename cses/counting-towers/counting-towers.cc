/* created   : 2021-02-17 21:11:41
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int mod = 1e9 + 7;
const int Z = 1e6 + 7;
ll f[Z][2];

void solve() {
  int N; cin >> N;
  // TLE: vector<vector<ll>> f(N + 2, vector<ll>(2));
  memset(f, 0, sizeof(f));
  f[1][0] = f[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    f[i][0] += f[i - 1][0];                  // both extend
    f[i][0] += 2 * f[i - 1][0];              // extend either side
    f[i][0] += (f[i - 1][0] + f[i - 1][1]);  // both not extend

    f[i][1] += f[i - 1][0];
    f[i][1] += 2 * f[i - 1][1];
    // 2 x 2
    // -------
    // |     |
    // |     |
    // -------

    f[i][0] %= mod;
    f[i][1] %= mod;
  }
  cout << (f[N][0] + f[N][1]) % mod << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
