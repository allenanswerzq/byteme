/*
 * created   : 2019-08-03 00:28:07
 * accepted  : 2019-08-03 13:48:21
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int m = 0;
  while (n /= 4) {
    m++;
  }
  int w = m + 1;
  ll ans = 0;
  int t = 1;
  for (int i = 0; i < (int) a.size(); i++) {
    ans += (ll)w * a[i];
    if (i == t - 1) {
      t *= 4;
      w--;
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
