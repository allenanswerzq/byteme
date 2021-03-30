/* created   : 2021-03-27 20:39:19
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 3>;

void solve() {
  // 8 7 1 1 1 7 7 7 8
  int N, M; cin >> N >> M;
  set<ar> st;
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x; cin >> x;
      st.insert({-x, i, j});
      A[i][j] = x;
    }
  }
  trace(st);
  vector<vector<int>> vis(N, vector<int>(M));
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  ll ans = 0;
  while (st.size()) {
    int max_height = -(*st.begin())[0];
    while (st.size()) {
      auto a = *st.begin();
      int x = a[1], y = a[2];
      if (-a[0] < max_height) break;
      if (!vis[x][y]) {
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if ((size_t) xx < N && (size_t) yy < M) {
            int new_height = max(max_height - 1, A[xx][yy]);
            ans += new_height - A[xx][yy];
            st.erase({-A[xx][yy], xx, yy});
            A[xx][yy] = new_height;
            st.insert({-new_height, xx, yy});
          }
        }
      }
      st.erase(st.begin());
    }
  }
  trace(A);
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
