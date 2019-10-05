//=============================================================
// Name        : 660a
// Date        : Fri Jun 28 18:26:32 CST 2019
// Accepted    : Fri Jun 28 18:34:02 CST 2019
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ans;
  int cnt = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans.push_back(a[i]);
    if (__gcd(a[i], a[i + 1]) != 1) {
      cnt++;
      ans.push_back(1);
    }
  }
  ans.push_back(a[n - 1]);
  cout << cnt << "\n";
  for (int i = 0; i < sz(ans); ++i) {
    cout << ans[i] << (i == sz(ans) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
