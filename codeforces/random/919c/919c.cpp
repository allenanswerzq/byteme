//=============================================================
// Name        : 919c
// Date        : Sun Jun  9 15:48:19 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

const int maxn = 2100;
char a[maxn][maxn];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
  }
  vector<vector<int>> sr(n + 1, vector<int>(m + 1));
  vector<vector<int>> sc(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      sr[i][j] = sr[i][j - 1] + (a[i - 1][j - 1] == '.');
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      sc[i][j] = sc[i - 1][j] + (a[i - 1][j - 1] == '.');
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = k; j <= m; ++j) {
      if (sr[i][j] - sr[i][j - k] == k) {
        ans++;
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = k; i <= n; ++i) {
      if (sc[i][j] - sc[i - k][j] == k) {
        ans++;
      }
    }
  }
  cout << (k == 1 ? ans / 2 : ans) << "\n";
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  solve();
  return 0;
}
