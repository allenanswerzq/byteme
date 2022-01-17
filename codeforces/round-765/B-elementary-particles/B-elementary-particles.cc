/* created   : 2022-01-17 23:00:39
 * accepted  : 2022-01-17 23:13:19
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 0 1 2 3 4 5 6
  // 3 1 5 2 1 3 4
  // greedy idea: its always better to chose the adjacent
  // numbers that are same.
  int N; cin >> N;
  map<int, vector<ar>> A;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    A[x].push_back({i, N - i - 1});
  }
  trace(N, A);
  int ans = 0;
  bool ok = false;
  for (auto it : A) {
    auto t = it.second;
    if (t.size() > 1) {
      ok = true;
    }
    for (int i = 0; i + 1 < t.size(); i++) {
      ans = max(ans, min(t[i][0], t[i + 1][0]) +
                     min(t[i][1], t[i + 1][1]));
    }
  }
  if (!ok) {
    cout << -1 << "\n";
  }
  else {
    cout << ans + 1 << "\n";
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
