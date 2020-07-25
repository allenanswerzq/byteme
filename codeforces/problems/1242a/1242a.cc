/* created   : 2020-02-03 09:39:44
 * accepted  : 2020-02-03 10:47:21
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

template <class T>
vector<pair<T, int>> factors(T n) {
  vector<pair<T, int>> fact;
  for (T i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      fact.push_back({i, cnt});
    }
  }
  if (n > 1) {
    fact.push_back({n, 1});
  }
  return fact;
}

void solve() {
  ll n; cin >> n;
  vector<pair<ll, int>> x = factors<ll>(n);
  if (x.size() == 1) {
    cout << x[0].x << '\n';
  }
  else {
    cout << 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
