/*
 * created   : 2019-07-25 19:15:45
 * accepted  : 2019-07-25 20:11:29
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = (1 << 30);
  for (int i = 0; i < n; ++i) {
    int x = upper_bound(a.begin(), a.end(), 2 * a[i]) - a.begin();
    ans = min(ans, n - x + i);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
