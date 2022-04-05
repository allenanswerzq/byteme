/* created   : 2021-02-11 08:24:18
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ar array<int, 2>
using ll = long long;

void solve() {
  int N; cin >> N;
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    mp[x] = i;
  }
  int ans = 1;
  for (int i = 2; i <= N; i++) {
    if (mp[i - 1] > mp[i]) {
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
