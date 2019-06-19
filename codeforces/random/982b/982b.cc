//=============================================================
// Name        : 982b
// Date        : Tue Jun 18 11:40:00 CST 2019
// Accepted    : Tue Jun 18 11:48:31 CST 2019
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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x;
    a[i].y = i;
  }
  string s;
  cin >> s;
  sort(a.rbegin(), a.rend());
  vector<pair<int, int>> b;
  vector<int> ans;
  for (int i = 0; i < 2 * n; ++i) {
    if (s[i] == '0') {
      auto t = a.back();
      a.pop_back();
      ans.push_back(t.y);
      b.push_back(t);
    } else {
      auto t = b.back();
      b.pop_back();
      ans.push_back(t.y);
    }
  }
  for (int i = 0; i < sz(ans); ++i) {
    cout << ans[i] + 1 << (i == sz(ans) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
