/* created   : 2021-08-08 08:48:12
 * accepted  : 2021-08-08 08:56:15
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int K; cin >> K;
  vector<vector<int>> A(K);
  map<ll, ar> mp;
  for (int i = 0; i < K; i++) {
    int len; cin >> len;
    ll sum = 0;
    for (int j = 0; j < len; j++) {
      int x; cin >> x;
      A[i].push_back(x);
      sum += x;
    }
    for (int j = 0; j < len; j++) {
      ll d = sum - A[i][j];
      if (mp.count(d) && mp[d][0] != i) {
        cout << "YES\n";
        cout << mp[d][0] + 1 << " " << mp[d][1] + 1 << "\n";
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
      mp[d] = {i, j};
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
