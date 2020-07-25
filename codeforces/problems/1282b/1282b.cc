/* created   : 2020-04-15 22:31:47
 * accepted  : 2020-04-15 23:27:37
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 7;
int a[N];
int f[N];
int ps[N];

void solve() {
  int n, p, k; cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    ps[i] = ps[i - 1] + a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i < k) {
      f[i] = ps[i];
    }
    else {
      f[i] = f[i - k] + a[i];
    }
    if (f[i] <= p) {
      ans = max(ans, i);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
