/* created   : 2020-11-01 10:25:26
 * accepted  : 2020-11-01 10:30:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int mod = 1e9 + 7;

int mul(int a, int b) { return (int)((ll)a * b % mod); }

int pow_mod(int x, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) ans = mul(ans, x);
    x = mul(x, x);
    p >>= 1;
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  cout << pow_mod(2, n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
