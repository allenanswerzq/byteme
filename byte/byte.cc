/* created   : 2020-08-23 20:58:09
 * accepted  : 2021-06-19 17:06:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

template <int N>
vector<int> sieve() {
  // Every number can be represented as i = lp[i] * x,
  // where lp[i] is the mininum prime factor, thus lp[i] <= lp[x]
  vector<int> lp(N);
  vector<int> pr;
  for (int i = 2; i < N; i++) {
    if (lp[i] == 0) {
      // i is a prime number
      lp[i] = i;
      pr.push_back(i);
    }
    trace(i);
    // Now, we know the mininum prime factor for i is lp[i]
    for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < N; j++) {
      trace(i, i * pr[j]);
      lp[i * pr[j]] = pr[j];
    }
  }
  return pr;
}

void solve() {
  sieve<100>();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
