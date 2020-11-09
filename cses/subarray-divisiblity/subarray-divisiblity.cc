/* created   : 2020-11-09 21:28:15
 * accepted  : 2020-11-09 22:49:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  // (s - t) % n == 0
  // (kn + t - t) % n
  // s%n == t%n
  int N; cin >> N;
  map<ll, int> cnt;
  cnt[0] = 1;
  ll sum = 0;
  ll ans = 0;
  ll r = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    sum += x;
    // NOTE: -5 % 100 = -5
    r = (sum % N + N) % N;
    ans += cnt[r];
    cnt[r]++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}

