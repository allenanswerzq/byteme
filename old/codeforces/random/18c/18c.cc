/*
 * created   : 2019-07-24 22:15:13
 * accepted  : 2019-07-24 22:17:41
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
  int n;
  cin >> n;
  vector<int> pr(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pr[i + 1] = pr[i] + x;
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (pr[i] == pr[n] - pr[i]) {
      ans++;
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
