//=============================================================
// Name        : 241a
// Date        : Sun Jul  7 10:55:42 CST 2019
// Accepted    : Sun Jul  7 11:02:53 CST 2019
// Author      : landcold7
// Description : Action speaks louder more than words
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int mx = 0;
  int fuel = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mx = max(x, mx);
    fuel += x;
    // Chose the maximum fuel supply place
    while (fuel < a[i]) {
      ans += k;
      fuel += mx;
    }
    fuel -= a[i];
    ans += a[i];
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
