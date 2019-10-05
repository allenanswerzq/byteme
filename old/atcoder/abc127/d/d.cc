/*
 * Creat       : Sat Jul 13 16:04:22 CST 2019
 * Accept      : Sat Jul 13 16:27:03 CST 2019
 * Author      : landcold7
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
  int n, m;
  cin >> n >> m;
  typedef pair<int, int> pii;
  priority_queue<pii, vector<pii>> dq;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    dq.push({x, 1});
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    dq.push({y, x});
  }
  ll ans = 0;
  while (n > 0) {
    auto p = dq.top();
    dq.pop();
    int x = min(n, p.y);
    ans += x * 1ll * p.x;
    n -= x;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
