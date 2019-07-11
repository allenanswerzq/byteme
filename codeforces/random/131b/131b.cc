//=============================================================
// Name        : 131b
// Date        : Tue Jun 25 14:30:52 CST 2019
// Accepted    : Tue Jun 25 14:40:09 CST 2019
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
  vector<int> cnt(22);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x + 10]++;
  }
  trace(cnt);
  ll ans = 0;
  for (int i = 0; i <= 10; ++i) {
    ll a = cnt[i], b = cnt[20 - i];
    if (i == 10) {
      ans += a * (a - 1) / 2;
    } else {
      ans += a * b;
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
