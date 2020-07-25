/* created   : 2020-04-05 16:59:44
 * accepted  : 2020-04-05 17:18:06
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
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  vector<string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const ll INF = 1e18 + 7;
  vector<vector<ll>> f(n + 1, vector<ll>(2, INF));
  f[0][0] = 0;
  f[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    string x = a[i - 1];
    string y = a[i];
    reverse(all(x));
    reverse(all(y));
    if (a[i] >= a[i - 1]) {
      f[i][0] = min(f[i][0], f[i - 1][0]);
    }
    if (a[i] >= x) {
      f[i][0] = min(f[i][0], f[i - 1][1]);
    }
    if (y >= a[i - 1]) {
      f[i][1] = min(f[i][1], f[i - 1][0] + c[i]);
    }
    if (y >= x) {
      f[i][1] = min(f[i][1], f[i - 1][1] + c[i]);
    }
  }
  ll ans = min(f[n][0], f[n][1]);
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
