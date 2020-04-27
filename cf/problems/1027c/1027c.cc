/* created   : 2020-04-27 19:41:51
 * accepted  : 2020-04-27 20:29:28
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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  vector<ll> b;  
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] == a[i + 1]) {
      b.push_back(a[i++]);
    }
  }
  assert(b.size() >= 2);
  ll x = b[0];
  ll y = b[1];
  ll p = (x + y) * (x + y);
  ll s = x * y;
  for (int i = 0; i + 1 < (int) b.size(); i++) {
    ll cp = (b[i] + b[i + 1]) * (b[i] + b[i + 1]);
    ll cs = b[i] * b[i + 1];
    if (cp * s < p * cs) {
      x = b[i];
      y = b[i + 1];
      p = cp;
      s = cs;
    }
  }
  cout << x << " " << x << " " << y << " " << y << "\n";
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
