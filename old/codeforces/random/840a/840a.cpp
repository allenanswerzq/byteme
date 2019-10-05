//=============================================================
// Name        : 840a
// Date        : Wed Jun 12 23:08:52 CST 2019
// Accepted    : Thu Jun 13 09:00:47 CST 2019
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
  vector<pair<int, int>> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i].x;
    b[i].y = i;
  }
  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[b[i].y] = a[i].x;
  }
  trace(ans);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
