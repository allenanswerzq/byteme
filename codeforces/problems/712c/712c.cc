/* created   : 2020-05-03 11:12:51
 * accepted  : 2020-05-03 11:14:51
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int x, y; cin >> x >> y;
  int a, b, c;
  a = b = c = y;
  int ans = 0;
  while (1) {
    if (a == x && b == x && c == x) {
      break;
    }
    ans++;
    if (ans % 3 == 0) {
      a = min(b + c - 1, x);
    }
    else if (ans % 3 == 1) {
      b = min(a + c - 1, x);
    }
    else {
      c = min(a + b - 1, x);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
