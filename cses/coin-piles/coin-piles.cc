/* created   : 2020-11-01 10:54:58
 * accepted  : 2020-11-01 11:24:08
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int a, b; cin >> a >> b;
  if (a > b) swap(a, b);
  if (b - 2 * a == 0) {
    cout << "YES\n";
  }
  else if (b - 2 * a > 0) {
    cout << "NO\n";
  }
  else {
    // b - 2 * a < 0
    // a == 2 * (b - 2 * i) + i
    // a == 2 * b - 4 * i + i
    // a == 2 * b - 3 * i
    int t = 2 * b - a;
    cout << ((t > 0 && t % 3 == 0) ? "YES\n" : "NO\n");
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
