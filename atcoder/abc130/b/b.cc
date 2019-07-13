/* Name        : b
 * Creat       : Fri Jul 12 22:19:06 CST 2019
 * Accept      : Fri Jul 12 22:24:29 CST 2019
 * Author      : landcold7
 * Action speaks louder more than words
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
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> d(n + 2);
  int ans = (d[1] <= x);
  for (int i = 2; i <= n + 1; ++i) {
    d[i] = d[i - 1] + a[i - 1];
    if (d[i] <= x) {
      ans++;
    }
  }
  trace(d);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
