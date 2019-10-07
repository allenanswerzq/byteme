/* created   : 2019-10-07 19:26:16
 * accepted  : 2019-10-07 21:45:31
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

template <class T>
vector<int> prime_factor(T n) {
  vector<int> fact;
  for (T i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    fact.push_back(n);
  }
  return fact;
}

void solve() {
  ll a, b; cin >> a >> b;
  ll g = __gcd(a, b);
  auto fact = prime_factor<ll>(g);
  cout << fact.size() + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
