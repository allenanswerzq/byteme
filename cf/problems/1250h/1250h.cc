/* created   : 2020-03-20 00:12:57
 * accepted  : 2020-03-21 13:21:19
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  vector<int> a(10);
  int mi = 1e9 + 7;
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
  }
  string ans;
  bool ok = false;
  for (int i = 1; i < 10; i++) {
    if (a[i] < mi + 1) {
      ok = true;
      ans = string(mi + 1, (char)(i + '0'));
      break;
    }
  }
  if (!ok) {
    ans = "1";
    ans += string(mi + 1, '0');
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
