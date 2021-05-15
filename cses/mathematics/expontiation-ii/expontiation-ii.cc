/* created   : 2020-12-17 21:58:32
 * accepted  : 2020-12-17 22:02:45
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

int mul(int a, int b, int mod) {
  return (ll)a * b % mod;
}

int pow(int a, int c, int mod) {
  int ans = 1;
  while (c) {
    if (c & 1) ans = mul(ans, a, mod);
    a = mul(a, a, mod);
    c >>= 1;
  }
  return ans;
}

void solve() {
  int N; cin >> N;
  const int mod = 1e9 + 7;
  for (int i = 0; i < N; i++) {
    int a, b, c; cin >> a >> b >> c;
    int t = pow(b, c, mod - 1);
    cout << pow(a, t, mod) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
