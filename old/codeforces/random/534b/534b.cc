/*
 * creat   : 2019-07-19 21:19:16
 * accept  : 2019-07-19 21:22:40
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
  int v1, v2, t, d;
  cin >> v1 >> v2 >> t >> d;
  vector<int> a(t);
  for (int i = 0; i < t; ++i) {
    a[i] = v1 + i * d;
  }
  vector<int> b(t);
  for (int i = 0; i < t; ++i) {
    b[t - i - 1] = v2 + i * d;
  }
  trace(a, b);
  int ans = 0;
  for (int i = 0; i < t; ++i) {
    a[i] = min(a[i], b[i]);
    ans += a[i];
  }
  trace(a);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
