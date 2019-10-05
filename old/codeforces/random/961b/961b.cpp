//=============================================================
// Name        : 961b
// Date        : Tue Jun 11 09:24:19 CST 2019
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (b[i] == 1) {
      sum += a[i];
    }
  }
  trace(sum, a, b, k);
  k--;
  ll pt = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 0) {
      pt += a[i];
    }
    if (i >= k) {
      ans = max(ans, sum + pt);
      if (b[i - k] == 0) {
        pt -= a[i - k];
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
