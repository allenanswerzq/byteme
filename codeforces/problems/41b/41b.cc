/* created   : 2020-03-26 22:52:42
 * accepted  : 2020-03-26 22:56:54
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define xuyixuyi()
#define debugstream ostream
#endif
typedef long long ll;

void solve() {
  int n, b; cin >> n >> b;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] > a[i]) {
        ans = max(ans, b / a[i] * a[j] + b % a[i]);
        ok = true;
      }
    }
  }
  cout << (!ok ? b : ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
