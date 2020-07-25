/* created   : 2020-04-18 21:11:01
 * accepted  : 2020-04-18 21:35:45
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  int g = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (i == 0) {
      g = x;
    }
    else {
      g = __gcd(g, x);
    }
    mx = max(mx, x);
  }
  g = mx / g - n;
  cout << (g % 2 ? "Alice" : "Bob") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
