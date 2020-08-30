/* created   : 2020-08-30 20:32:11
 * accepted  : 2020-08-30 21:41:43
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  unordered_map<int, int> cnt;
  cnt[0] = 1;
  ll ans = 0;
  int lo = 0;
  int prefix_sum = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    prefix_sum += x;
    lo = min(lo, prefix_sum);
    for (int k = 0; k < 10000; k++) {
      int cur = prefix_sum - k * k;
      if (cur < lo) break;
      if (cnt.count(cur)) {
        ans += cnt[cur];
      }
    }
    cnt[prefix_sum]++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
