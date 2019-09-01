/* created   : 2019-08-14 23:13:21
 * accepted  : 2019-08-14 23:18:18
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int s = 0;
    while (x) {
      s += x % 10;
      x /= 10;
    }
    a[i] = s;
  }
  trace(a);
  vector<bool> use(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!use[i] && !use[j] && (a[i] + a[j]) % 3 == 0) {
        ans++;
        use[i] = 1;
        use[j] = 1;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
