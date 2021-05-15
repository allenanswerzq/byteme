/* created   : 2020-10-29 08:01:21
 * accepted  : 2020-10-29 08:04:55
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  ll n; cin >> n;
  while (1) {
    cout << n << " ";
    if (n == 1) break;
    if (n & 1) n = 3 * n + 1;
    else n /= 2;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
