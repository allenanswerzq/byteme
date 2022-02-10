/* created   : 2022-01-21 08:26:53
 * accepted  : 2022-01-21 09:00:46
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  ll N, M; cin >> N >> M;
  if (N < M) {
    swap(N, M);
  }
  vector<ll> ans;
  for (ll i = 0; i < N * M; i++) {
    ar x = {i / M, i % M};
    trace(x);
    ar p1 = {N - 1, M - 1};
    ar p2 = {N - 1, 0};
    ar p3 = {0, M - 1};
    ar p4 = {0, 0};
    ll t = abs(x[0] - p1[0]) + abs(x[1] - p1[1]);
    ll c = abs(x[0] - p2[0]) + abs(x[1] - p2[1]);
    ll w = abs(x[0] - p3[0]) + abs(x[1] - p3[1]);
    ll z = abs(x[0] - p4[0]) + abs(x[1] - p4[1]);
    ans.push_back(max({t, c, w, z}));
  }
  sort(all(ans));
  for (int i = 0; i < N * M; i++) {
    cout << ans[i] << (i == N * M - 1 ? '\n' : ' ');
  }
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
