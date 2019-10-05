/*
 * creat   : 2019-07-19 10:14:21
 * accept  : 2019-07-19 11:30:12
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
  int n, h, k;
  cin >> n >> h >> k;
  ll ans = 0;
  ll cur = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (cur + x <= h) {
      cur += x;
    }
    else {
      ans++, cur = x;
    }
    ans += cur / k;
    cur = cur % k;
  }
  ans += (cur + k - 1) / k;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
