/* created   : 2020-03-13 19:32:36
 * accepted  : 2020-03-13 22:59:32
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

const int N = 52;
int f[N][2];

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[n][1] = a[n];
  f[n][0] = 0;
  for (int i = n - 1; i >= 1; i--) {
    f[i][1] = max(f[i + 1][1], f[i + 1][0] + a[i]);
    f[i][0] = min(f[i + 1][1], f[i + 1][0] + a[i]);
  }
  cout << f[1][0] << ' ' << f[1][1] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
