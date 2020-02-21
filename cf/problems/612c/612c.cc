/* created   : 2020-02-17 22:15:03
 * accepted  : 2020-02-19 22:56:55
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
  string s; cin >> s;
  map<char, char> right;
  right[']'] = '[';
  right['}'] = '{';
  right['>'] = '<';
  right[')'] = '(';
  int ans = 0;
  vector<char> stk;
  stk.clear();
  for (int i = 0; i < s.size(); i++) {
    if (right.count(s[i])) {
      if (stk.empty()) {
        cout << "Impossible" << '\n';
        return;
      }
      else if (stk.back() == right[s[i]]) {
        stk.pop_back();
      }
      else {
        stk.pop_back();
        ans++;
      }
    }
    else {
      stk.push_back(s[i]);
    }
  }
  if (stk.size() > 0) {
    cout << "Impossible" << '\n';
    return;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
