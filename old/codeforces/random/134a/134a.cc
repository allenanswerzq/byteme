//=============================================================
// Name        : 134a
// Date        : Sun Jul  7 09:36:54 CST 2019
// Accepted    : Sun Jul  7 09:40:18 CST 2019
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
  int n;
  cin >> n;
  vector<int> a(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    ll x = sum - a[i];
    if (x % (n - 1) == 0 && x / (n - 1) == a[i]) {
      ans.push_back(i);
    }
  }
  cout << sz(ans) << "\n";
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
