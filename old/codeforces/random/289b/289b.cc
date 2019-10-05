/*
 * Creat   : 2019-07-15 15:56:33
 * Accept  : 2019-07-15 16:11:07
 * Author  : landcold7
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
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(n * m);
  for (int i = 0; i < n * m; ++i) {
    cin >> a[i];
  }
  trace(a);
  for (int i = 0; i < n * m; ++i) {
    for (int j = i + 1; j < n * m; ++j) {
      if (a[i] % d != a[j] % d) {
        cout << -1 << "\n";
        return;
      }
    }
  }
  sort(a.begin(), a.end());
  int v = a[(n * m) / 2];
  trace(a, v);
  ll ans = 0;
  for (int i = 0; i < n * m; ++i) {
    ans += abs(v - a[i]) / d;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
