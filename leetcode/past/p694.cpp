#include <bits/stdc++.h>
using namespace std;

bool dfs(int sx, int sy, int x, int y, vvi& grid, vvi&visit, vvi& island) {
  int m = grid.size(), n = grid[0].size();
  vvi dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
  if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y] == 1 || grid[x][y] == 0)
    return 0;
  visit[x][y] = 1;
  island.push_back({x - sx, y - sy});
  for (int i = 0; i < 4; ++i) {
    dfs(sx, sy, x+dirs[i][0], y+dirs[i][1], grid, visit, island);
  }
  return true;
}

int numDistinctIslands(vvi& grid) {
  int m = grid.size(), n = grid[0].size();
  // denotes every island as a vector<vector<int>> contains (x-sx, y-sy)
  // if two islands is the same, then we got same two dimension vector
  set<vvi> islands;
  vvi visit(m, vi(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      vvi island;
      if (dfs(i, j, i, j, grid, visit, island))
      islands.insert(island);
    }
  }
  return islands.size();
}

int main() {
  return 0;
}
