//=============================================================
// Name        : 653b
// Date        : Sun Jun 30 09:42:58 CST 2019
// Accepted    : Sun Jun 30 10:37:56 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<string>> cnt(26);
  for (int i = 0; i < m; ++i) {
    string x, y;
    cin >> x >> y;
    cnt[y[0] - 'a'].push_back(x);
  }
  // trace(cnt, a);
  int ans = 0;
  vector<string> a = {"a"};
  for (int i = 0; i < n - 1; ++i) {
    vector<string> b;
    for (auto t : a) {
      int ix = t[0] - 'a';
      b.insert(b.begin(), cnt[ix].begin(), cnt[ix].end());
    }
    a = b;
    ans = (int) b.size();
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
