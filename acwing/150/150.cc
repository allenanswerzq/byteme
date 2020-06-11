/* created   : 2020-06-10 19:39:43
 * accepted  : 2020-06-11 06:11:23
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

bool not_match(char x, char y) {
  bool ret = 0;
  ret |= (x == '(' && y == ')');
  ret |= (x == '[' && y == ']');
  ret |= (x == '{' && y == '}');
  return !ret;
}

void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<int> stk;
  for (int i = 0; i < n; i++) {
    char ch = s[i];
    if (ch == '(' || ch == '[' || ch == '{') {
      stk.push_back(i);
    }
    else {
      if (stk.empty() || not_match(s[stk.back()], s[i])) {
        stk.push_back(i);
      }
      else {
        stk.pop_back();
      }
    }
  }
  stk.insert(stk.begin(), -1);
  stk.push_back(n);
  int ans = 0;
  for (int i = 0; i + 1 < stk.size(); i++) {
    ans = max(ans, stk[i + 1] - stk[i] - 1);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
