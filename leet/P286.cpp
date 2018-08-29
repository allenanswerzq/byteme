#include<bits/stdc++.h>
using namespace std;

// You are given a m x n 2D grid initialized with these three possible values.
// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent 
// INF as you may assume that the distance to a gate is less than 2147483647. 
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, 
// it should be filled with INF.
// For example, given the 2D grid:
 
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// After running your function, the 2D grid should be:
 
//  3  -1   0   1
//  2   2   1  -1
//  1  -1   2  -1
//  0  -1   3   4

// dfs
void dfs(vector<vector<int>>& rooms, int x, int y) {
	int m = rooms.size(), n = rooms[0].size();
	vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0, 1}};	
	for (int k = 0; k < 4; ++k) {
		int nx = x + dirs[k][0]; 
		int ny = y + dirs[k][1];
		if (0<=nx && nx<m && 0<=ny && ny<n && rooms[nx][ny] > rooms[x][y] + 1) {
			rooms[nx][ny] = rooms[x][y] + 1; 
			dfs(rooms, nx, ny);
		}
	}
}

void wallsAndGatesDfs(vector<vector<int>>& rooms) {
	int m = rooms.size(), n = rooms[0].size();
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j)
			if (rooms[i][j] == 0) {
				dfs(rooms, i, j);
			}
}

// multi-end bfs
// the core idea of multi-end is that starting from multiple point
// compared to normal bfs we can save a lot time to do repate work
vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0, 1}};	
void wallsAndGates(vector<vector<int>>& rooms) {
	int m = rooms.size(), n = rooms[0].size();
	if (m == 0) return;
	queue<int> q;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (rooms[i][j] == 0)
				q.push(i * n + j);

	while (!q.empty()) {
		int p = q.front(); q.pop();	
		int x = p / n, y = p % n;
		for (int k = 0; k < 4; k++) {
			int nx = x + dirs[k][0];
			int ny = y + dirs[k][1];	
			if (nx>=0 && nx<m && ny>=0 && ny<n && rooms[nx][ny] > rooms[x][y] + 1) {
				rooms[nx][ny] = rooms[x][y] + 1;
				q.push(nx * n + ny);
			}
		}
	}
}


// Normal bfs
void bsf(vector<vector<int>>& rooms, int i, int j) {
	int m=rooms.size(), n=rooms[0].size();
	queue<int> q;
	q.push(i*n + j);
	while(!q.empty()) {
		int p = q.front(); q.pop();
		int x = p/n, y = p%n;
		for (int i=0; i<4; ++i) {
			int nx = x + dirs[k][0];
			int ny = y + dirs[k][1];	
			if (nx>=0 && nx<m && ny>=0 && ny<n && rooms[nx][ny] > rooms[x][y]+1) {
				rooms[nx][ny] = rooms[x][y]+1;
				q.push(nx*n + ny);
			}

		}
	}
}

void wallsAndGates(vector<vector<int>>& rooms) {
	int m=rooms.size(), n=rooms[0].size();
	if (m == 0) return;
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			if (rooms[i][j] == 0)
				bfs(rooms, i, j);
}

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
    printf("%8d\t", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

int main() {
	vector<vector<int>> rooms = {
		{INF,  -1,  0 , INF},
		{INF, INF, INF,  -1},
		{INF,  -1, INF,  -1},
	  {0,  -1, INF, INF},
	};	
	printMatrix(rooms);
	wallsAndGates(rooms);
	printMatrix(rooms);
}
