/* created   : 2020-05-03 16:16:35
 * accepted  : 2020-05-03 20:20:13
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

vector<int> factors(ll x) {
  vector<int> ans;
  for (ll i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      x /= i;
      ans.push_back(i);
    }
  }
  if (x > 1) {
    ans.push_back(x);
  }
  return ans;
}

void solve() {
  ll n; cin >> n;
  auto x = factors(n);
  trace(x);
  int m = x.size();
  if (n == 1 || m == 1) {
    cout << 1 << "\n";
    cout << 0 << "\n";
  }
  else if (m == 2) {
    cout << 2 << "\n";
  }
  else {
    cout << 1 << "\n";
    cout << x[0] * 1ll * x[1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
