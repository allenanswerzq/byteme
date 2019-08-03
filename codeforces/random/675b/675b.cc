/*
 * creat   : 2019-07-19 15:51:41
 * accept  : 2019-07-19 15:58:03
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
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  set<string> st;
  for (int x = 1; x <= n; ++x) {
    int y = x - (c - b);
    int f = x + (a - d);
    int g = f - (c - b);
    trace(x, y, f, g);
    if (1 <= y && y <= n && 1 <= f && f <= n && 1 <= g && g <= n) {
      string pt = to_string(x) + "_" + to_string(y) + "_" +
                  to_string(f) + "_" + to_string(g);
      st.insert(pt);
    }
  }
  trace(st);
  ll ans = (ll) st.size() * n;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
