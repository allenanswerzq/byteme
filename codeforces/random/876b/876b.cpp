//=============================================================
// Name        : 876b
// Date        : Fri Jun 14 16:22:26 CST 2019
// Accepted    : Fri Jun 14 17:20:18 CST 2019
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

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> cnt(m);
  vector<vector<int>> ans(m);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x % m]++;
    ans[x % m].push_back(x);
  }
  int ix = -1;
  for (int i = 0; i < m; ++i) {
    if (cnt[i] >= k) {
      ix = i;
      break;
    }
  }
  if (ix == -1) {
    cout << "No" << "\n";
    return;
  }
  cout << "Yes" << "\n";
  for (int i = 0; i < k; ++i) {
    cout << ans[ix][i] << (i == k - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
