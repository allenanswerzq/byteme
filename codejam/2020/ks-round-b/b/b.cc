/* created   : 2020-04-19 07:07:47
 * accepted  : 2020-04-19 07:33:38
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, d; cin >> n >> d;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> b(n);
  for (int i = n - 1; i >= 0; i--) {
    b[i] = d / a[i] * a[i];
    d = b[i];
  }
  trace(d, a, b);
  cout << b[0] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
