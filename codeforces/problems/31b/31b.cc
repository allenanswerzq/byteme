/* created   : 2020-03-21 19:49:37
 * accepted  : 2020-03-21 23:08:09
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
  string s; cin >> s;
  vector<int> a;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '@') {
      a.push_back(i);
    }
  }
  int m = a.size();
  bool ok = true;
  if (a.empty() || a[0] == 0 || a.back() == n - 1) {
    ok = false;
  }
  for (int i = 0; i + 1 < m; i++) {
    if (a[i + 1] - a[i] <= 2) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << "No solution" << '\n';
    return;
  }
  trace(a);
  string ans;
  int lo = 0;
  for (int i = 0; i < m; i++) {
    ans += s.substr(lo, a[i] + 1 - lo + 1);
    if (i < m - 1) {
      ans += ",";
    }
    lo = a[i] + 2;
  }
  for (int i = a.back() + 2; i < n; i++) {
    ans += s[i];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
