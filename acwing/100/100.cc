/* created   : 2020-05-22 10:40:39
 * accepted  : 2020-05-22 17:54:26
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 7;
ll a[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll x = 0;
  ll y = 0;
  for (int i = 2; i <= n; i++) {
    ll c = a[i] - a[i - 1];
    if (c > 0) {
      x += c;
    }
    else {
      y -= c;
    }
  }
  cout << max(x, y) << "\n";
  cout << abs(x - y) + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
