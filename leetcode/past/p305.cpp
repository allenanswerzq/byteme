#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

// A 2d grid map of m rows and n columns is initially filled with water. 
// We may perform an addLand operation which turns the water at position (row, col) into a land. 
// Given a list of positions to operate, count the number of islands after 
// each addLand operation. An island is surrounded by water and 
// is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.

// Example:

// Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
// Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

// 0 0 0
// 0 0 0
// 0 0 0
// Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

// 1 0 0
// 0 0 0   Number of islands = 1
// 0 0 0
// Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

// 1 1 0
// 0 0 0   Number of islands = 1
// 0 0 0
// Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

// 1 1 0
// 0 0 1   Number of islands = 2
// 0 0 0
// Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

// 1 1 0
// 0 0 1   Number of islands = 3
// 0 1 0
// We return the result as an array: [1, 1, 2, 3]

// Challenge:

// Can you do it in time complexity O(k log mn), where k is the length of the positions?

#define vi vector<int>
#define vvi vector<vi>
#define pii <pair<int, int>
#define vpii vector<pair<int, int>>

int find(vi& roots, int ix) {
  while (roots[ix] != ix) {
    ix = roots[ix]; 
  } 
  return ix;
}

class Solution {
public:
  vi numIslands2(int m, int n, vpii& aa) {
    vi res;
    vi roots(m * n, -1);
    int cnt = 0;
    vvi dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    fora (a, aa) {
      int x = a.first, y = a.second;
      int id = n * x + y;
      // trace(id, x, y);
      roots[id] = id;
      // pvi(roots);
      ++cnt;
      fori (i, 0, 4) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        int cur_id = nx * n + ny; 
        // trace(nx, ny, cur_id);
        if (!(0<=nx && nx<m && 0<=ny && ny<n) || roots[cur_id] == -1) continue;
        int p = find(roots, id);
        int q = find(roots, cur_id); 
        // trace(nx, ny, p, q);
        if (p != q) {
          roots[q] = p;
          --cnt;
        }
      }
      // pvi(roots);
      res.push_back(cnt);
    }
    return res;
  } 
};

void test(int m, int n, vpii& aa) {
  Solution go;
  vi res = go.numIslands2(m, n, aa);
  pvi(res);
}

int main() {
  return 0;
}
