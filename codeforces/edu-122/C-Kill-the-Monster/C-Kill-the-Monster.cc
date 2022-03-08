/* created   : 2022-03-06 23:40:41
 * accepted  : 2022-03-08 23:55:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

void solve() {
  ll Hc, Dc; cin >> Hc >> Dc;
  ll Hm, Dm; cin >> Hm >> Dm;
  ll K, W, A; cin >> K >> W >> A;
  // int tm = ceil(Hm / (Dc + x * W))
  // int tc = ceil((Hc + A * y) / Dm)
  // x + y = K
  for (int i = 0; i <= K; i++) {
    ll tm = ceil(Hm, Dc + i * W);
    ll tc = ceil(Hc + (K - i) * A, Dm);
    // character attacks first, so equal also works
    if (tc >= tm) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
