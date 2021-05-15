/* created   : 2020-11-05 12:45:50
 * accepted  : 2020-11-05 12:50:14
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<pair<int, int>> A;
  for (int i = 0; i < N; i++) {
    int b, e; cin >> b >> e;
    A.push_back(make_pair(b, -1));
    A.push_back(make_pair(e, 1));
  }
  sort(all(A));
  trace(A);
  int ans = 0;
  int cur = 0;
  for (auto& it : A) {
    cur += it.second;
    ans = max(ans, -cur);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
