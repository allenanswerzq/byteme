/* created   : 2020-11-05 12:58:08
 * accepted  : 2020-11-05 18:57:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  for (auto& a : A) {
    cin >> a.second >> a.first;
  }
  sort(all(A));
  int ans = 0;
  int cur = 0;
  for (int i = 0; i < N; i++) {
    if (A[i].second >= cur) {
      ans++;
      cur = A[i].first;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
