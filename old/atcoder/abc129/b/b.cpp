//=============================================================
// Name        : b
// Date        : Mon Jun 10 10:13:13 CST 2019
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
  vector<int> a(n), pr(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pr[i + 1] = pr[i] + a[i];
  }
  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    int s1 = pr[i + 1] - pr[0];
    int s2 = pr[n] - pr[i + 1];
    ans = min(ans, abs(s1 - s2));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
