/* created   : 2021-06-05 15:41:01
 * accepted  : 2021-06-05 20:22:38
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

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
  int N; cin >> N;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
