/* created   : 2019-12-19 23:28:49
 * accepted  : 2019-12-19 23:53:38
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

const ll mod = 2147483648;

void add(ll &a, ll b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int N = 4200;
ll f[N];

void solve() {
  int n; cin >> n;
  f[0] = 1;
  // f[i][j] = max(f[i][j - v] + w, f[i - 1][j])
  // stage
  for (int i = 1; i <= n; i++) {
    // i------- j -----i - 1
    // state
    for (int j = i; j <= n; j++) {
      add(f[j], f[j - i]);
    }
  }
  trace(mt(f, n + 1));
  cout << f[n] - 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
