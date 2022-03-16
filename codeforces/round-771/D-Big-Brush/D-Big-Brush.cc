/* created   : 2022-03-16 19:02:20
 * accepted  : 2022-03-16 22:35:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> vis(N, vector<int>(M));
  vector<array<int, 3>> ans;
  auto check = [&](int x, int y) {
    if (x < 0 || x + 1 >= N || y < 0 || y + 1 >= M) return;
    if (vis[x][y]) return;
    vector<int> tmp;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        int c = A[x + i][y + j];
        if (c != -1) {
          tmp.push_back(c);
        }
      }
    }
    if (tmp.empty()) return;
    sort(all(tmp));
    if (tmp[0] != tmp.back()) return;
    ans.push_back({x, y, tmp[0]});
    vis[x][y] = 1;
  };

  for (int i = 0; i + 1 < N; i++) {
    for (int j = 0; j + 1 < M; j++) {
      check(i, j);
    }
  }
  trace(ans);
  for (int i = 0; i < ans.size(); i++) {
    int x = ans[i][0];
    int y = ans[i][1];
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        A[x + j][y + k] = -1;
      }
    }
    // (x, y)
    for (int j = -1; j <= 1; j++) {
      for (int k = -1; k <= 1; k++) {
        check(x + j, y + k);
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      ok &= (A[i][j] == -1);
    }
  }
  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  cout << ans.size() << "\n";
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2] << "\n";
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
