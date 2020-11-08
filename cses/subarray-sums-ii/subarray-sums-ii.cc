/* created   : 2020-11-08 22:11:53
 * accepted  : 2020-11-08 22:28:09
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, X; cin >> N >> X;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  map<ll, int> cnt;
  cnt[0] = 1;
  ll ans = 0;
  ll sum = 0;
  for (int a : A) {
    sum += a;
    if (cnt.count(sum - X)) {
      ans += cnt[sum - X];
    }
    cnt[sum]++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
