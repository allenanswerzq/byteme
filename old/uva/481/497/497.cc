/*
 * creat   : 2019-07-18 08:56:39
 * accept  : 2019-07-18 09:10:33
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
  string s;
  vector<int> a;
  while (getline(cin, s) && s != "") {
    istringstream iss(s);
    int x;
    iss >> x;
    a.push_back(x);
  }
  trace(a);
  int n = (int) a.size();
  vector<pair<int, int>> dp(n, {1, -1});
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i] && dp[j].x + 1 > dp[i].x) {
        dp[i] = {dp[j].x + 1, j};
      }
    }
  }
  pair<int, int> best = {0, -1};
  for (int i = n - 1; i >= 0; --i) {
    if (dp[i].x > best.x) {
      best = {dp[i].x, i};
    }
  }
  trace(best, dp);
  int cur = best.y;
  vector<int> ans;
  while (cur != -1) {
    ans.push_back(a[cur]);
    cur = dp[cur].y;
  }
  trace(ans);
  cout << "Max hits: " << best.x << "\n";
  for (int i = best.x - 1; i >= 0; --i) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n >> ws;
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << "\n";
    }
    solve();
  }
  return 0;
}
