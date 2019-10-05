/*
 * creat   : 2019-07-18 20:10:28
 * accept  : 2019-07-18 20:24:05
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

int go(int a) {
  assert(0 <= a && a <= 100);
  int x = 10;
  while (x < a) {
    x += 10;
  }
  return (x - a);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].y;
    a[i].x = go(a[i].y);
  }
  sort(a.begin(), a.end());
  trace(a);
  for (int i = 0; i < n && k > 0; ++i) {
    if (a[i].x > 0) {
      int mi = min(a[i].x, k);
      a[i].y += mi;
      k -= mi;
    }
  }
  for (int i = 0; i < n && k > 0; ++i) {
    int mi = min(100 - a[i].y, k);
    a[i].y += mi;
    k -= mi;
  }
  trace(a);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i].y / 10;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
