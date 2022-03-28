/* created   : 2022-03-28 20:22:03
 * accepted  : 2022-03-28 22:55:12
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  int N, M; cin >> N >> M;
  unordered_map<int, vector<ar>> mp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x; cin >> x;
      mp[x].push_back({i, j});
    }
  }
  // i=0, s1,s2,...k-1
  // i=1,    s2,...k-1
  // i=2,      s3..
  ll ans = 0;
  for (auto & it : mp) {
    vector<ll> row, col;
    for (ar p : it.second) {
      row.push_back(p[0]);
      col.push_back(p[1]);
    }
    sort(all(row));
    sort(all(col));
    for (int i = 0; i < (int) row.size(); i++) {
      ans += row[i] * (2 * i + 1 - (int) row.size()) ;
    }
    for (int i = 0; i < col.size(); i++) {
      ans += col[i] * (2 * i + 1 - (int) col.size()) ;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
