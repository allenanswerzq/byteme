/* created   : 2020-04-12 22:22:46
 * accepted  : 2020-04-12 23:09:58
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
  vector<int> a(n);
  int one = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    one += a[i] == 1;
  }
  const int INF = 1e9 + 7;
  int ans = (one > 0 ? n - one : INF);
  trace(ans, one);
  for (int i = 0; i < n; i++) {
    int g = a[i];
    for (int j = i + 1; j < n; j++) {
      g = __gcd(g, a[j]);
      if (g == 1) {
        ans = min(ans, n - 1 + j - i);
        break;
      }
    }
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
