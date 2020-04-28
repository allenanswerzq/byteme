/* created   : 2020-04-28 23:24:30
 * accepted  : 2020-04-28 23:55:29
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, d, h; cin >> n >> d >> h;
  if ((d == 1 && n != 2) || d - h > h) {
    cout << -1 << "\n";
    return;
  }
  for (int i = 1; i <= h; i++) {
    cout << i << " " << i + 1 << "\n";
  }
  int x = 1;
  for (int i = 1; i <= d - h; i++) {
    int y = h + 1 + i;
    cout << x << " " << y << "\n";
    x = y;
  }
  for (int i = d + 2; i <= n; i++) {
    cout << i << " " << (h == h ? 2 : 1) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
