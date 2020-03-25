/* created   : 2020-03-25 23:27:47
 * accepted  : 2020-03-25 23:41:21
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
#define xuyixuyi()
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  vector<int> ans;
  int m = s.size();
  int lo = 0;
  for (; lo + a <= m && ans.size() < n; lo += a) {
    ans.push_back(a);
  }
  if (ans.size() < n) {
    cout << "No solution" << '\n';
    return;
  }
  trace(ans, lo);
  assert(ans.size() == n);
  int left = m - lo;
  for (int i = 0; i < ans.size(); i++) {
    int mi = min(left, b - a);
    trace(i, left, mi);
    if (mi == 0) break;
    ans[i] += mi;
    lo += mi;
    left -= mi;
  }
  if (left > 0) {
    cout << "No solution" << '\n';
    return;
  }
  trace(ans);
  lo = 0;
  for (int i = 0; i < n; i++) {
    cout << s.substr(lo, ans[i]) << '\n';
    lo += ans[i];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
