/* created   : 2020-02-08 12:40:09
 * accepted  : 2020-02-08 12:56:21
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
  string a; cin >> a;
  vector<char> stk;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (!stk.empty() && a[i] == stk.back()) {
      stk.pop_back();
    }
    else {
      stk.push_back(a[i]);
    }
  }
  string ans(all(stk));
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
