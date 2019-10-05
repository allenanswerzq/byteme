/* created   : 2019-08-25 21:47:29
 * accepted  : 2019-08-25 21:50:06
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  vector<int> use(n);
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    x--;
    use[x] = 1;
    b[i] = a[x];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      ans += a[i];
    }
  }
  sort(b.begin(), b.end(), greater<int>());
  for (int i = 0; i < m; i++) {
    if (ans > b[i]) {
      ans += ans;
    }
    else {
      ans += b[i];
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
