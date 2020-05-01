/* created   : 2020-05-01 10:11:17
 * accepted  : 2020-05-01 10:36:11
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int t; cin >> t;
  int g = t * 180 / __gcd(t, 180);
  int n = g / t;
  int x = g / 180;
  if (x == n - 1) {
    n *= 2;
  }
  cout << n << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  } cin.tie(0);
  return 0;
}
