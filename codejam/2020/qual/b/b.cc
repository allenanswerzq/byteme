/* created   : 2020-04-04 08:40:54
 * accepted  : 2020-04-04 09:23:21
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s; cin >> s;
  vector<char> stk;
  for (int i = 0; i < s.size(); i++) {
    int cur = s[i] - '0';
    if (stk.empty()) {
      for (int j = 0; j < cur; j++) {
        stk.push_back('(');
      }
      stk.push_back(s[i]);
      for (int j = 0; j < cur; j++) {
        stk.push_back(')');
      }
    }
    else {
      if (s[i] == '0') {
        stk.push_back(s[i]);
        continue;
      }
      int have = 0;
      while (!stk.empty() && stk.back() == ')') {
        have++;
        stk.pop_back();
        if (have >= cur) {
          break;
        }
      }
      if (have >= cur) {
        stk.push_back(s[i]);
        while (have-- > 0) {
          stk.push_back(')');
        }
      }
      else {
        int need = cur - have;
        for (int j = 0; j < need; j++) {
          stk.push_back('(');
        }
        stk.push_back(s[i]);
        for (int j = 0; j < need; j++) {
          stk.push_back(')');
        }
        while (have-- > 0) {
          stk.push_back(')');
        }
      }
    }
  }
  string ans;
  for (int i = 0; i < stk.size(); i++) {
    ans += stk[i];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
