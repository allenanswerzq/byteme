/* created   : 2020-04-30 16:07:25
 * accepted  : 2020-04-30 17:19:54
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }
  ll ans = 0;
  for (int i = m - 1; i >= 0; i--) {
    ll cur = 0;
    vector<bool> seen(n);
    for (int j = i - 1; j >= 0; j--) {
      if (b[j] == b[i]) {
        break;
      }
      if (!seen[b[j]]) {
        seen[b[j]] = true;
        cur += a[b[j]];
      }
    }
    trace(i, cur);
    ans += cur;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
