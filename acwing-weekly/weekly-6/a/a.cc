/* created   : 2021-08-01 07:59:36
 * accepted  : 2021-08-01 08:01:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  ll sum = 0;
  for (int & a : A) {
    cin >> a;
    sum += a;
  }
  int ans = 0;
  for (int a : A) {
    if ((sum - a) % 2 == 0) {
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
