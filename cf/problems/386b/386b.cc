/* created   : 2020-04-04 22:20:34
 * accepted  : 2020-04-04 22:30:20
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
  int t; cin >> t;
  sort(all(a));
  trace(a);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = 1;
    for (int j = i + 1; j <= n; j++) {
      if (j == n || a[j] - a[i] > t) {
        cur = j - i;
        break;
      }
    }
    ans = max(cur, ans);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
