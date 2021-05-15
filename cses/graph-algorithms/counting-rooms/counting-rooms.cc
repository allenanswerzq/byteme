/* created   : 2020-11-14 10:05:56
 * accepted  : 2020-11-14 10:11:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<string> A(N);
  for (string& a : A) {
    cin >> a;
  }
  vector<int> dx = {0, 0, -1, 1};
  vector<int> dy = {-1, 1, 0, 0};
  std::function<void(int, int)> dfs = [&](int x, int y) {
    A[x][y] = '#';
    for (int k = 0; k < 4; k++) {
      size_t xx = x + dx[k];
      size_t yy = y + dy[k];
      if (xx < N && yy < M && A[xx][yy] == '.') {
        dfs(xx, yy);
      }
    }
  };
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == '.') {
        dfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
