/* created   : 2020-06-20 07:33:50
 * accepted  : 2020-06-20 07:52:52
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

string dfs(string& s, int& u) {
  u++;
  vector<string> child;
  while (s[u] == '0') {
    child.push_back(dfs(s, u));
  }
  u++;
  sort(all(child));
  string ans = "0";
  for (auto ch : child) ans += ch;
  ans += "1";
  return ans;
}

void solve() {
  string a, b; cin >> a >> b;
  int ua = 0, ub = 0;
  a = "0" + a + "1";
  b = "0" + b + "1";
  if (dbg(dfs(a, ua)) == dfs(b, ub)) {
    cout << "same\n";
  }
  else {
    cout << "different\n";
  }
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
