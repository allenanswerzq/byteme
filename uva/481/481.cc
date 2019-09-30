/*
 * creat   : 2019-07-17 15:46:32
 * accept  : 2019-07-17 18:53:03
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int x;
  vector<int> a;
  while (cin >> x) {
    a.push_back(x);
  }
  int n = (int) a.size();
  trace(a);
  vector<int> lis(n + 1);
  vector<int> dp(n + 1);
  vector<int> pr(n + 1);
  int ans = 0;
  int end = 0;
  for (int i = 0; i < n; ++i) {
    auto ix = lower_bound(lis.begin(), lis.begin() + ans, a[i]) - lis.begin();
    lis[ix] = a[i];
    pr[i] = ix ? dp[ix - 1] : -1;
    dp[ix] = i;
    if (ix == ans) {
      ans++;
      end = i;
    }
  }
  vector<int> path;
  int cur = end;
  while (cur != -1) {
    path.push_back(a[cur]);
    cur = pr[cur];
  }
  cout << ans << "\n";
  cout << "-" << "\n";
  for (int i = ans - 1; i >= 0; --i) {
    cout << path[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
