#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x);
    printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
	printf("{\n");
	for (auto x:v)
		printVector(x);
	printf("}\n");
}

// Accepted
bool dfs(int startx, int starty, int x, int y, vector<vector<int>>& grid, vector<vector<int>>&visit, vector<vector<int>>& island) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    if (x<0 || x>=m || y<0 || y>=n || visit[x][y]==1 || grid[x][y]==0) return false;
    visit[x][y] = 1;
    island.push_back({x-startx, y-starty});
    //printf("------------------------------\n");
    //printf("(%d %d) --> (%d %d)\n", startx, starty, x, y);
    //printMatrix(island);
    //printMatrix(visit);

    for (int i=0; i<4; ++i) {
      dfs(startx, starty, x+dirs[i][0], y+dirs[i][1], grid, visit, island);
    }
    return true;
}

int numDistinctIslands(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  // denotes every island as a vector<vector<int>> contains (x-startx, y-starty)
  // if two islands is the same, then we got same two dimension vector
  set<vector<vector<int>>> islands;
  vector<vector<int>> visit(m, vector<int>(n, 0));

  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      vector<vector<int>> island;
      if(dfs(i, j, i, j, grid, visit, island))
        islands.insert(island);
    }
  }
  return islands.size();
}

int main(int argc, char** argv) {
    return 0;
}
