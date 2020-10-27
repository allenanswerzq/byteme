/* created   : 2020-10-26 21:50:45
 * accepted  : 2020-10-27 08:02:06
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, K; cin >> N >> K;
  vector<pair<ll, ll>> A(N);
  for (auto &a : A) {
    cin >> a.first >> a.second;
  }
  sort(all(A));
  ll ans = 0;
  for (int i = 0; i < N; ) {
    ll s = A[i].first;
    ll e = A[i].second;
    ll c = (e - s + K - 1) / K;
    ans += c;
    e = s + c * K;
    trace(A, c, s, e);
    int j = i + 1;
    while (j < N && A[j].second <= e) j++;
    i = j;
    if (i >= N) break;
    A[i].first = max(A[i].first, e);
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
