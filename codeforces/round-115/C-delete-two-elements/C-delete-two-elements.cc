/* created   : 2022-01-09 15:37:32
 * accepted  : 2022-01-09 16:18:18
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // (n - 2) * s(1,n) = s(1,n-2) * n
  int N; cin >> N;
  ll s = 0;
  map<ll, ll> mp;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    mp[x]++;
    s += x;
  }
  // ll t = s * (N - 2); note: this will overflow
  // s * (N - 2) % N
  if ((s % N) * ((N - 2) % N) % N != 0) {
    cout << 0 << "\n";
    return;
  }
  // ll d = s - s * (N - 2) / N;
  //      = (N * s - s * N + 2 * s) / N = 2 * s / N
  ll d = 2 * s / N;
  ll ans = 0;
  for (auto it = mp.begin(); it != mp.end(); ) {
    ll x = it->first;
    ll y = d - x;
    if (!mp.count(y)) {
      it++;
      continue;
    }
    if (x != y) {
      ans += it->second * mp[y];
      it = mp.erase(it);
    }
    else {
      ans += it->second * (it->second - 1) / 2;
      it++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
