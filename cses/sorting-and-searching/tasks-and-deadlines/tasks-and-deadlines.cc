/* created   : 2020-11-08 11:10:24
 * accepted  : 2020-11-08 14:51:21
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  //      [_____a_____][___b___]
  // #1: da - a + db - (a + b) = da + db - 2a - b
  // swap [___b___][_____a_____]
  // #2: da - (a + b) + db - b = da + db - a - 2b
  // #1 - #2 = -2a - b + a + 2b = b - a < 0
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  for (auto& a : A) {
    cin >> a.first >> a.second;
  }
  sort(all(A));
  ll sum = 0;
  ll ans = 0;
  for (auto& a : A) {
    trace(A, ans, sum);
    ans += a.second - (sum + a.first);
    sum += a.first;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
