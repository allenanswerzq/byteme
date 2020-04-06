/* created   : 2020-04-05 18:51:47
 * accepted  : 2020-04-05 21:48:04
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  cout << n - 1 + m - 1 + n * m << '\n';
  string ans;
  ans += string(n - 1, 'U');
  ans += string(m - 1, 'L');
  for (int i = 0; i < n; i++) {
    ans += string(m - 1, (i % 2 ? 'L' : 'R'));
    ans += 'D';
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
