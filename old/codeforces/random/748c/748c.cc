/*
 * created   : 2019-08-01 09:44:15
 * accepted  : 2019-08-01 11:43:04
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  const int INF = (1 << 30);
  vector<int> dp(n + 1, INF);
  string dir = "LRUD";
  map<char, int> pr;
  for (auto c : dir) {
    pr[c] = -1;
  }
  dp[0] = 0;
  map<char, char> mp;
  mp['L'] = 'R';
  mp['R'] = 'L';
  mp['U'] = 'D';
  mp['D'] = 'U';
  for (int len = 1; len <= n; len++) {
    char ch = s[len - 1];
    int x = -1;
    for (auto c : dir) {
      if (c != ch) {
        x = max(x, pr[c]);
      }
    }
    if (x >= 0 && s[x] != mp[ch]) {
      int t = -1;
      for (auto c : dir) {
        if (c != ch && c != s[x]) {
          t = max(t, pr[c]);
        }
      }
      x = t;
    }
    if (x + 1 <= n) {
      dp[len] = min(dp[len], dp[x + 1] + 1);
    }
    pr[ch] = len - 1;
  }
  cout << dp[n] << "\n";
}

void solve_greedy() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int x = 0;
  int y = 0;
  int ans = 1;
  for (auto c : s) {
    int dx = 0;
    int dy = 0;
    if (c == 'L') {
      dx = -1;
    }
    else if (c == 'R') {
      dx = 1;
    }
    else if (c == 'U') {
      dy = -1;
    }
    else {
      dy = 1;
    }
    if (x * dx == -1 || y * dy == -1) {
      x = 0;
      y = 0;
      ans++;
    }
    if (x == 0) {
      x = dx;
    }
    if (y == 0) {
      y = dy;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve_greedy();
  return 0;
}
