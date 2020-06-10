/* created   : 2020-06-10 19:39:43
 * accepted  : 2020-06-10 20:15:10
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  string s; cin >> s;
  int ans = 0;
  int last = -1;
  int len = 0;
  vector<char> stk;
  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (ch == '(' || ch == '[' || ch == '{') {
      stk.push_back(i);
    }
    else {
      if (stk.empty()) continue;
      int p = stk.back();
      stk.pop_back();
      if (!((s[p] == '(' && s[i] == ')') ||
           (s[p] == '[' && s[i] == ']') ||
           (s[p] == '{' && s[i] == '}'))) continue;
      int cur = i - p + 1;
      trace(i, p, last, len);
      if (last + 1 == p) {
        cur += len;
      }
      ans = max(ans, cur);
      last = i;
      len = cur;
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
