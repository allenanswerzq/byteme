/* created   : 2020-02-16 17:41:47
 * accepted  : 2020-02-16 18:29:22
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
  string s, t; cin >> s >> t;
  unordered_map<char, char> key;
  for (int i = 0; i < s.size(); i++) {
    if (key.count(s[i])) {
      if (key[s[i]] != t[i]) {
        cout << -1 << '\n';
        return;
      }
    }
    else {
      if (key.count(t[i])) {
        cout << -1 << '\n';
        return;
      }
      else {
        key[s[i]] = t[i];
        key[t[i]] = s[i];
      }
    }
  }
  set<pair<char, char>> ans;
  for (auto it : key) {
    char a = it.x;
    char b = it.y;
    if (a == b) continue;
    if (a > b) swap(a, b);
    ans.insert({a, b});
  }
  cout << ans.size() << '\n';
  trace(ans);
  for (auto it : ans) {
    cout << it.x << ' ' << it.y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
