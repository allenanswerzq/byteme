//=============================================================
// Name        : 959b
// Date        : Sun Jun 16 08:58:44 CST 2019
// Accepted    : Sun Jun 16 09:58:29 CST 2019
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
  int n, k, m;
  cin >> n >> k >> m;
  vector<string> word(n);
  for (int i = 0; i < n; ++i) {
    cin >> word[i];
  }
  vector<int> cost(n);
  for (int i = 0; i < n; ++i) {
    cin >> cost[i];
  }
  vector<int> group(k, (1 << 30));
  unordered_map<string, int> mp;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      int y;
      cin >> y;
      y--;
      group[i] = min(group[i], cost[y]);
      mp[word[y]] = i;
    }
  }
  ll ans = 0;
  vector<string> msg(m);
  for (int i = 0; i < m; ++i) {
    cin >> msg[i];
    ans += group[mp[msg[i]]];
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
