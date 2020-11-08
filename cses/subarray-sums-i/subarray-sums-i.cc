/* created   : 2020-11-08 21:53:09
 * accepted  : 2020-11-08 22:08:01
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
  vector<ll> ps(N + 1);
  for (int i = 0; i < N; i++) {
    ps[i + 1] = ps[i] + A[i];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    auto l = lower_bound(ps.begin(), ps.begin() + i + 1, ps[i + 1] - X);
    auto h = upper_bound(ps.begin(), ps.begin() + i + 1, ps[i + 1] - X);
    if (l != h) {
      // trace(ps, i, h - l);
      ans += (h - l);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
