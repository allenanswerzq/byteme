#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

vector<vector<char>> g;
int dfs(int x, int y) {
  if (x<0 || x==g.size() || y<0 || y==g[0].size() || g[x][y]=='0')
    return 0;

  // turn whole island into water
  g[x][y] = '0'; 
  dfs(x+1, y);
  dfs(x-1, y);
  dfs(x, y+1);
  dfs(x, y-1);

  return 1;
}

int numIslands(vector<vector<char>>& grid) {
  int cnt = 0;  
  g = grid;
  for (int i=0; i<g.size(); ++i) 
    for (int j=0; j<g[0].size(); ++j)
     cnt += dfs(i, j);
  return cnt;
}

int main(int argc, char** argv) {

    return 0;
}
