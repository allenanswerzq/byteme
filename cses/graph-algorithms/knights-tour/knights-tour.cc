/* created   : 2020-11-24 17:48:18
 * accepted  : 2020-11-24 18:04:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int N = 8;
vector<int> dx = {-1, 1, -1, 1, -2, -2, 2, 2};
vector<int> dy = {-2, -2, 2, 2, -1, 1, -1, 1};
int vis[N][N];

int moves(array<int, 2> a) {
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int xx = a[0] + dx[i];
    int yy = a[1] + dy[i];
    if ((size_t)xx < N && (size_t)yy < N && !vis[xx][yy]) {
      ans++;
    }
  }
  return ans;
}

// Warnsdorff's rule
// https://en.wikipedia.org/wiki/Knight%27s_tour
void dfs(int x, int y, int c) {
  vis[x][y] = c + 1;
  if (c == 63) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << vis[i][j] << (j == N - 1 ? '\n' : ' ');
      }
    }
    exit(0);
  }
  vector<array<int, 2>> cand;
  for (int i = 0; i < N; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if ((size_t)xx < N && (size_t)yy < N && !vis[xx][yy]) {
      cand.push_back({xx, yy});
    }
  }
  sort(all(cand), [&](const array<int, 2>& a, const array<int, 2>& b){
    // Choose the place where the next possible moves is smaller first.
    return moves(a) < moves(b);
  });
  for (auto& t : cand) {
    dfs(t[0], t[1], c + 1);
  }
  vis[x][y] = 0;
}

void solve() {
  int x, y; cin >> x >> y;
  x--, y--;
  swap(x, y);
  dfs(x, y, 0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
