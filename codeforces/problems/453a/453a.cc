/* created   : 2020-04-12 10:07:07
 * accepted  : 2020-04-12 10:09:02
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int m, n; cin >> m >> n;
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += (pow(i * 1.0 / m, n) - pow((i - 1) * 1.0 / m, n)) * i;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
