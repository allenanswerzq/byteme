/* created   : 2020-05-01 15:23:40
 * accepted  : 2020-05-01 16:08:55
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  for (ll i = 1; i <= n; i++) {
    if (i == 1) {
      cout << 2 << "\n";
    }
    else {
      cout << i * (i + 1) * (i + 1) - (i - 1) << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
