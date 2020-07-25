/* created   : 2020-04-06 11:17:10
 * accepted  : 2020-04-06 11:18:58
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
      ans++;
    }
    if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
      ans++;
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
