/*
 * created   : 2019-08-05 09:41:09
 * accepted  : 2019-08-05 09:52:53
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int m;
  cin >> m;
  vector<int> d(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(d.begin(), d.end());
  sort(a.begin(), a.end(), greater<int>());
  trace(d, a);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d[0] && i < n; j++) {
      ans += a[i++];
    }
    if (i < n) {
      i += 2;
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
