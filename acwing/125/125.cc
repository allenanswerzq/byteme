/* created   : 2020-05-31 20:48:30
 * accepted  : 2020-05-31 21:55:55
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  vector<int> xx(n);
  vector<int> yy(n);
  for (int i = 0; i < n; i++) {
    cin >> xx[i] >> yy[i];
  }
  sort(all(yy));
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    ans += (yy[n - i - 1] - yy[i]);
  }
  sort(all(xx));
  for (int i = 0; i < n; i++) {
    xx[i] = xx[i] - i;
  }
  sort(all(xx));
  for (int i = 0; i < n / 2; i++) {
    ans += (xx[n - i - 1] - xx[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
