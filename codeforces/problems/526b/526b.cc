/* created   : 2019-10-27 12:56:40
 * accepted  : 2019-10-27 13:53:22
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 20000;
int g[N];
int n;

int rec(int u, int& sum) {
  if (u >= (1 << n)) {
    return 0;
  }
  int sa = 0;
  int sb = 0;
  int a = rec(u * 2, sa);
  int b = rec(u * 2 + 1, sb);
  int mx = max(g[u * 2] + sa, g[u * 2 + 1] + sb);
  int ret = a + b;
  ret += 2 * mx - g[u * 2] - g[u * 2 + 1] - sa - sb;
  sum = mx;
  return ret;
}

void solve() {
  cin >> n;
  for (int i = 2; i <= (1 << (n + 1)) - 1; i++) {
    cin >> g[i];
  }
  int lights = 0;
  int ans = rec(1, lights);
  trace(ans, lights);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
