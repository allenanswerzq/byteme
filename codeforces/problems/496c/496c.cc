/* created   : 2020-04-18 11:09:03
 * accepted  : 2020-04-18 15:05:03
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    bool ok = true;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i].substr(0, j + 1) > a[i + 1].substr(0, j + 1)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      ans++;
      for (int i = 0; i < n; i++) {
        a[i] = a[i].substr(0, j) + a[i].substr(j + 1);
      }
      j--;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
