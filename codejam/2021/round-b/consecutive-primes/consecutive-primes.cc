/* created   : 2021-05-22 09:09:33
 * accepted  : 2021-05-22 10:30:03
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

bool is_prime(ll n) {
  if (n == 2 || n == 3) {
    return true;
  }
  else if (n <= 1 || (n % 2) == 0 || (n % 3) == 0) {
    return false;
  }
  ll i = 5;
  while (i * i <= n) {
    if ((n % i) == 0 || (n % (i + 2)) == 0) {
      return false;
    }
    i += 6;
  }
  return true;
}

ll solve(ll Z) {
  ll sq = (ll)sqrt(Z);
  ll n = 500;
  vector<ll> P;
  for (ll i = sq; i >= max(sq - n, 0ll); i--) {
    if (is_prime(i)) {
      P.push_back(i);
    }
  }
  for (ll i = sq + 1; i <= min(sq + n, (ll) 1e18); i++) {
    if (is_prime(i)) {
      P.push_back(i);
    }
  }
  sort(all(P));
  ll ans = 0;
  for (int i = (int) P.size() - 1; i >= 0; i--) {
    if (P[i] * P[i - 1] <= Z)
      return P[i] * P[i - 1];
  }
  assert(ans != 0);
  return ans;
}

ll solve_brute_force(ll Z) {
  vector<ll> P;
  for (ll i = 2; i <= 2021; i++) {
    if (is_prime(i)) {
      P.push_back(i);
    }
  }
  for (int i = (int) P.size() - 1; i >= 0; i--) {
    if (P[i] * P[i - 1] <= Z)
      return P[i] * P[i - 1];
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    ll Z; cin >> Z;
    cout << solve(Z) << "\n";
    //
    // for (ll i = 6; i <= 2021; i++) {
    //   ll a = solve(i);
    //   ll b = solve_brute_force(i);
    //   trace(i, a, b);
    //   assert(a == b);
    // }
  }
  return 0;
}
