/* created   : 2019-12-28 09:55:18
 * accepted  : 2019-12-28 12:47:02
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

int lower(int x) {
  // 2^0 + 2^1 + ... + 2^(k - 1) = 2^k - 1 <= x
  int k = 0;
  while (((1 << k) - 1) <= x) {
    k++;
  }
  return k - 1;
}

const int M = 1e5 + 7;
bool f[M];
int a[120];
int c[120];
int n;
int m;

// multiple group knapsack.
void solve1() {
  trace(n, m);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  trace(mt(a, n + 1), mt(c, n + 1));
  memset(f, 0, sizeof(f));
  f[0] = true;
  for (int i = 1; i <= n; i++) {
    int p = lower(c[i]);
    for (int j = 0; j < p; j++) {
      int val = (1 << j) * a[i];
      for (int k = m; k >= val; k--) {
        f[k] |= f[k - val];
      }
    }
    int r = (c[i] - ((1 << p) - 1));
    trace(c[i], p, r);
    for (int k = m; k >= r * a[i]; k--) {
      f[k] |= f[k - r * a[i]];
    }
  }
  trace(mt(f, m + 1));
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += f[i];
  }
  cout << ans << '\n';
}

void solve() {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  f[0] = true;
  for (int i = 1; i <= n; i++) {
    vector<int> use(m + 1);
    // Note the loop direction.
    for (int j = a[i]; j <= m; j++) {
      if (!f[j] && f[j - a[i]] && use[j - a[i]] < c[i]) {
        f[j] = true;
        use[j] = use[j - a[i]] + 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += f[i];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n >> m && n && m) {
    solve();
  }
  return 0;
}

