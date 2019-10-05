/*
 * creat   : 2019-07-20 08:18:29
 * accept  : 2019-07-20 08:55:20
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
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int m;
  cin >> m;
  vector<pair<int, int>> b(m);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    b[i].x = mp[x];
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    b[i].y = mp[x];
  }
  int ans = max_element(b.begin(), b.end()) - b.begin();
  cout << ans + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
