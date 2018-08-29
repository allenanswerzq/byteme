#include<bits/stdc++.h>
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

// You want to build a house on an empty land which reaches all buildings 
// in the shortest amount of distance. You can only move up, down, left and right. 
// You are given a 2D grid of values 0, 1 or 2, where:

// Each 0 marks an empty land which you can pass by freely.
// Each 1 marks a building which you cannot pass through.
// Each 2 marks an obstacle which you cannot pass through.
// For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

// 1 - 0 - 2 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
// The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

// Note:
// There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  int shortestDistance(vvi& gg) {
    int res = (1<<30);
    int m = sz(gg), n = sz(gg[0]); 
    int buildings_cnt = 0;
    // The sum distances from a point `(x, y)` to all buildings.
    int dist[m][n]; mst(dist, 0);
    // The number of buildings can reach from a position `(x,y)`.
    int count[m][n]; mst(count, 0); 
    vvi dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    fori (i, 0, m) {
      fori (j, 0, n) {
        if (gg[i][j] == 1) {
          ++buildings_cnt; 
          deque<pair<int, int>> dq;
          dq.push_back({i, j});
          int visit[m][n]; mst(visit, 0);
          int level = 1;
          while (sz(dq)) {
            int nn = sz(dq);
            fori (k, 0, nn) {
              int x = dq.front().first;
              int y = dq.front().second; dq.pop_front();
              fora (d, dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (0<=nx && nx<m && 0<=ny && ny<n && 
                    gg[nx][ny] == 0 && !visit[nx][ny]) {
                  // trace(x, y, nx, ny);
                  dist[nx][ny] += level;
                  ++count[nx][ny];
                  visit[nx][ny] = 1;
                  dq.push_back({nx, ny}); 
                }
              }
            }
            ++level;
          }
        }
      }
    }
    // trace(buildings_cnt);
    fori (i, 0, m) 
      fori (j, 0, n) 
        if (gg[i][j] == 0 && count[i][j] == buildings_cnt)
          res = min(res, dist[i][j]); 
    return res;
  }
};

void test(vvi& inp, int right) {
  Solution go;
  int res = go.shortestDistance(inp);
  trace(res, right);
  assert(res == right);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  vvi aa = {{1, 0, 2, 0, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0}};

  test(aa, 7);

  return 0;
}
