/* created   : 2020-04-24 19:23:13
 * accepted  : 2020-04-24 19:25:49
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  ll g = a * b / __gcd(a, b);
  cout << n / a * p + n / b * q - n / g * min(p, q) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
