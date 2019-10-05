/* Name        : d
 * Creat       : Sat Jul 13 08:45:06 CST 2019
 * Accept      : Sat Jul 13 09:10:50 CST 2019
 * Author      : landcold7
 * Motto       : Action speaks louder more than words
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
  ll n, k;
  cin >> n >> k;
  vector<ll> pr(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    pr[i] = pr[i - 1] + x;
  }
  trace(pr);
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    // k + pr[i] <= pr[j]
    int p = lower_bound(pr.begin(), pr.end(), pr[i] + k) - pr.begin();
    ans += (n + 1 - p);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
