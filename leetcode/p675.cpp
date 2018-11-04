#include<bits/stdc++.h>
using namespace std;

int bfs(vvi& forest, int src_x, int src_y, int dest_x, int dest_y) {
  if (src_x == dest_x && src_y == dest_y) return 0;
  int level = 0;
  queue<pii> q;
  q.push({src_x, src_y});
  int m = forest.size(), n = forest[0].size();
  vvi visit(m, vi(n, 0));
  visit[src_x][src_y] = 1;
  vvi dir = { {-1,0}, {1,0}, {0,1}, {0,-1} };
  while (!q.empty()) {
    int nq = q.size();
    level++;
    for (int k = 0; k < nq; ++k) {
      int cur_x = q.front().first;
      int cur_y = q.front().second;
      q.pop();
      for (int i=0; i<4; ++i) {
        int x = cur_x + dir[i][0];
        int y = cur_y + dir[i][1];
        if (x>=0 && x<m && y>=0 && y<n && forest[x][y]>0 && visit[x][y]==0) {
          if (x==dest_x && y==dest_y) return level;
          visit[x][y] = 1;
          q.push({x, y});
        }
      }
    }
  }
  return -1;
}

int dfs(vvi& forest, int src_x, int src_y, int dest_x, int dest_y, vvi visit) {
  int m = forest.size(), n = forest[0].size();
  if (src_x==dest_x && src_y==dest_y) return 0;
  if (visit[src_x][src_y] == 1) return -1;
  visit[src_x][src_y] = 1;
  vvi dir = { {-1,0}, {1,0}, {0,1}, {0,-1} };
  int walks = INT_MAX;
  for (int i = 0; i < 4; ++i) {
    int x = src_x + dir[i][0];
    int y = src_y + dir[i][1];
    if (x >= 0 && x < m && y >= 0 && y< n && forest[x][y]>0) {
      int level = dfs(forest, x, y, dest_x, dest_y, visit);
      if (level >= 0)
      walks = min(walks, level);
    }
  }
  visit[src_x][src_y] = 0;
  return walks==INT_MAX ? -1:walks+1;
}

int cutOffTree(vvi& forest) {
  int m = forest.size(), n = forest[0].size();
  if (m <= 0) return -1;

  vvi height;
  for (int i=0; i<m; ++i) for (int j=0; j<n; ++j)
    if (forest[i][j] > 1) height.push_back({forest[i][j], i, j});

  // Sort according to height
  sort(height.begin(), height.end());

  // Sum all the shortest distance between each adjacent height points
  int x = 0, y = 0;
  int walks = 0;
  vvi visit(m, vector<int>(n, 0));
  for (int i = 0; i < height.size(); ++i) {
    int level = dfs(forest, x, y, height[i][1], height[i][2], visit);
    if (level == -1) return -1;
    walks += level;
    x = height[i][1];
    y = height[i][2];
  }
  return walks;
}
