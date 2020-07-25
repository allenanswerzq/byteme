/* created   : 2020-04-12 10:10:39
 * accepted  : 2020-04-12 10:12:20
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
    if (!stk.empty() && stk.back() == s[i]) {
      stk.pop_back();
    }
    else {
      stk.push_back(s[i]);
    }
  }
  cout << (stk.empty() ? "Yes" : "No") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
