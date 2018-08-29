#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> gg;
int dfs(int x, int y) {
  if (! (0<=x && x <gg.size() && 0<=y && y<gg[0].size()) || gg[x][y] == '0')
    return 0;
  // Turn whole island into water.
  gg[x][y] = '0'; 
  dfs(x+1, y);
  dfs(x-1, y);
  dfs(x, y+1);
  dfs(x, y-1);
  return 1;
}

int numIslands(vector<vector<char>>& grid) {
  int cnt = 0;  
  gg = grid;
  for (int i=0; i < gg.size(); ++i) 
    for (int j=0; j < gg[0].size(); ++j)
      cnt += dfs(i, j);
  return cnt;
}

int main(int argc, char** argv) {

    return 0;
}
