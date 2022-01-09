/* created   : 2022-01-09 16:23:45
 * accepted  : 2022-01-09 17:48:41
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

ll C(int n, int k) {
  if (k == 3) {
    return (ll) n * (n - 1) * (n - 2) / 6;
  }
  else if (k == 2) {
    return (ll) n * (n - 1) / 2;
  }
  else {
    assert(false);
    return 0;
  }
}

void solve() {
  int N; cin >> N;
  map<int, int> topic;
  map<int, int> diff;
  vector<ar> A(N);
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    topic[x]++;
    diff[y]++;
    A[i] = {x, y};
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    int x = A[i][0], y = A[i][1];
    // (x, y) (x, _) (_, y)
    if (topic[x] > 0 && diff[y] > 0) {
      ans += (topic[x] - 1) * 1ll * (diff[y] - 1);
    }
  }
  cout << C(N, 3) - ans << "\n";
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
