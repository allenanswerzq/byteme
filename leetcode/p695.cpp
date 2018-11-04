#include<bits/stdc++.h>
using namespace std;

int path = 0;
void dfs(vvi& grid, int x, int y, vvi& visit) {
  int m = grid.size(), n = grid[0].size();
  vvi dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
  visit[x][y] = 1;
  path++;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dirs[i][0];
    int ny = y + dirs[i][1];
    if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && visit[nx][ny]==0 ) {
      dfs(grid, nx, ny, visit);
    }
  }
  return;
}

int maxAreaOfIsland(vvi& grid) {
  int res = 0;
  int m = grid.size(), n = grid[0].size();
  vvi visit(m, vi(n, 0));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        path = 0;
        dfs(grid, i, j, visit);
        res = max(res, path);
      }
    }
  return res;
}

int main() {
  return 0;
}
