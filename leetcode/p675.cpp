#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& forest, int src_x, int src_y, int dest_x, int dest_y) {
  if (src_x == dest_x && src_y == dest_y) return 0;
  int step = 0;
  queue<pair<int, int>> q;
  q.push({src_x, src_y});
  int m = forest.size(), n = forest[0].size();
  // https://stackoverflow.com/questions/26451034/why-do-i-need-the-visited-state-in-breadth-first-search
  vector<vector<int>> visited(m, vector<int>(n, 0)); // Note
  visited[src_x][src_y] = 1;
  vector<vector<int>> dir = { {-1,0}, {1,0}, {0,1}, {0,-1} };
  while(!q.empty()) {
  int nq = q.size();
  step++; // walk one step 
  for (int k=0; k<nq; ++k) {
    int cur_x = q.front().first;
    int cur_y = q.front().second;
    q.pop();
    for (int i=0; i<4; ++i) {
    int x = cur_x + dir[i][0];
    int y = cur_y + dir[i][1];
    if (x>=0 && x<m && y>=0 && y<n && forest[x][y]>0 && visited[x][y]==0) {
      if (x==dest_x && y==dest_y) return step;
      visited[x][y] = 1;
      q.push({x, y});
    }
    }
  }
  }
  return -1;
} 

// https://stackoverflow.com/questions/1294720/whats-the-difference-between-backtracking-and-depth-first-search
// turns out this dfs will cause infinte loop
int dfs(vector<vector<int>>& forest, int src_x, int src_y, int dest_x, int dest_y, vector<vector<int>> visited) {
  int m = forest.size(), n = forest[0].size();
  if (src_x==dest_x && src_y==dest_y) return 0;
  if (visited[src_x][src_y] == 1) return -1;
  visited[src_x][src_y] = 1;
  vector<vector<int>> dir = { {-1,0}, {1,0}, {0,1}, {0,-1} };
  int walks = INT_MAX;
  for (int i=0; i<4; ++i) {
  int x = src_x + dir[i][0];
  int y = src_y + dir[i][1];
  if (x>=0 && x<m && y>=0 && y<n && forest[x][y]>0) {
    int step = dfs(forest, x, y, dest_x, dest_y, visited);
    if (step >= 0)
    walks = min(walks, step);
  }
  } 
  visited[src_x][src_y] = 0;  // Note: why?
  return walks==INT_MAX ? -1:walks+1;
}

int cutOffTree(vector<vector<int>>& forest) {
  int m = forest.size(), n = forest[0].size();
  if (m <= 0) return -1;
  
  // each vector contains {height, x, y}
  vector<vector<int>> height;  
  for (int i=0; i<m; ++i)
  for (int j=0; j<n; ++j)
    if (forest[i][j] > 1) height.push_back({forest[i][j], i, j});

  // sort according to height 
  sort(height.begin(), height.end());

  // sum all the shortest distance between each adjacent height points
  int x=0, y=0;
  int walks = 0;
  vector<vector<int>> visited(m, vector<int>(n, 0));
  for (int i=0; i<height.size(); ++i) {
  // int step = bfs(forest, x, y, height[i][1], height[i][2]); 
  int step = dfs(forest, x, y, height[i][1], height[i][2], visited); 
  if (step == -1) return -1;
  walks += step;
  x = height[i][1];
  y = height[i][2];
  }
  return walks;
}
