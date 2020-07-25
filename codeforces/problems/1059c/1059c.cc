/* created   : 2020-02-08 20:44:34
 * accepted  : 2020-02-08 22:29:16
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

void rec(int n, int mul, vector<int>& ans) {
  if (n == 1) {
    ans.push_back(mul);
  }
  else if (n == 2) {
    ans.push_back(mul);
    ans.push_back(mul * 2);
  }
  else if (n == 3) {
    ans.push_back(mul);
    ans.push_back(mul);
    ans.push_back(mul * 3);
  }
  else {
    for (int i = 1; i <= n; i += 2) {
      ans.push_back(mul);
    }
    rec(n / 2, mul * 2, ans);
  }
}

void solve() {
  int n; cin >> n;
  vector<int> ans;
  rec(n, 1, ans);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
