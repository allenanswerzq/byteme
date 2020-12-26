/* created   : 2020-12-26 10:40:25
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, K; cin >> N >> K;
  double ans = 0;
  for (int i = 1; i <= K; i++) {
    double p = pow(i * 1.0 / K, N) - pow((i - 1) * 1.0 / K, N);
    ans += p * i;
    trace(i, p, ans);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << setprecision(6) << fixed;
  solve();
  return 0;
}
