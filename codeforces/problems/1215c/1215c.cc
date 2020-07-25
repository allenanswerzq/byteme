/* created   : 2020-02-06 11:02:30
 * accepted  : 2020-02-06 11:13:59
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
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' && t[i] == 'b') {
      a.push_back(i + 1);
    }
    else if (s[i] == 'b' && t[i] == 'a') {
      b.push_back(i + 1);
    }
    else {
    }
  }
  int na = a.size();
  int nb = b.size();
  vector<pair<int, int>> ans;
  for (int i = 0; i + 1 < na; i += 2) {
    ans.push_back({a[i], a[i + 1]});
  }
  for (int i = 0; i + 1 < nb; i += 2) {
    ans.push_back({b[i], b[i + 1]});
  }
  if (na % 2 && nb % 2) {
    ans.push_back({a.back(), a.back()});
    ans.push_back({a.back(), b.back()});
  }
  else if (na % 2 || nb % 2) {
    cout << -1 << '\n';
    return;
  }
  cout << ans.size() << '\n';
  for (auto tmp : ans) {
    cout << tmp.x << ' ' << tmp.y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
