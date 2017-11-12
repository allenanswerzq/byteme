#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

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

// Finally, accepted
int path = 0;
void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visit) {
    //printf("_________Enter_________\n");
  int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	visit[x][y] = 1;
    //printMatrix(visit)
    //printf("(%d %d) --> ", x,y);
	path++;
	for (int i=0; i<4; ++i) {
		int new_x = x+dirs[i][0];
		int new_y = y+dirs[i][1];
        //if (new_x==0 && new_y==1) {printf("XXXX%d %d\n", x, y);}
		if (new_x>=0 && new_x<m && new_y>=0 && new_y<n && grid[new_x][new_y]==1 && visit[new_x][new_y]==0 ) {
            //if (x==0 && y==1) {printf("new (%d %d)\n", new_x, new_y);}
            //printf("new (%d %d)\n", new_x, new_y);
			dfs(grid, new_x, new_y, visit);
		}
	}
	//visit[x][y] = 0; Note: dont need this line
    //printf("_________Exit_______________\n");
    //printMatrix(visit);
	return;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int res = 0;
	int m = grid.size(), n = grid[0].size();
  vector<vector<int>> visit(m, vector<int>(n,0));
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j) {
			if (grid[i][j] == 1) {
				path = 0;
        //printf("==================================\n");
				dfs(grid, i, j, visit);
				res = max(res, path);
			}
		}
	return res;
}

int main(int argc, char** argv) {
    return 0;
}
