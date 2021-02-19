/* created   : 2021-02-17 21:11:41
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int mod = 1e9 + 7;

void solve() {
  int N; cin >> N;
  vector<vector<ll>> f(N + 2, vector<ll>(2));
  f[N + 1][0] = f[N + 1][1] = 1;
  for (int i = N; i >= 2; i--) {
    ll op1 = f[i + 1][0];
    ll op2 = (f[i + 1][0] + f[i + 1][1]) % mod;
    ll op3 = 2 * f[i + 1][0] % mod;
    ll op4 = f[i + 1][1];

    f[i][0] = (op1 + op2 + op3) % mod;
    f[i][1] = (op1 + op4) % mod;
  }
  cout << (f[2][0] + f[2][1]) % mod << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
