#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <random>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <unistd.h>
using namespace std;

#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define fora(e, c) for (auto &e : c)
#define all(x) (x).begin(), (x).end()
#define len(x) strlen(x)
#define vi vector<int>
#define vs vector<string>
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf pop_front
#define ppb pop_back
#define pvi(x) fora(r, x) cout << r << ' '; cout << '\n'
#define cerr(x) cerr << #x " is " << (x) << endl
#define mst(x, n, v) fori(i, 0, n) x[i] = v
#define mst2(x, n, m, v) fori(i, 0, n) fori(j, 0, m) x[i][j] = v
#define mst3(x, n, m, c, v) \
        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double eps = 1e-9;
int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
class ChessMetric {
public:
  ll dp[120][120][60];
  ll howMany(int size, vi start, vi end, int numMoves) {
    mst3(dp, 120, 120, 60, 0);
    vector<vi> dirs = {{0, 1}, {0, -1}, {1,0}, {-1, 0},
               {1, 1}, {-1, -1  }, {1, -1}, {-1, 1},
               {-2, 1}, {-2, -1}, {2, 1}, {2, -1},
               {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    dp[start[0]][start[1]][0] = 1;
    fori(move, 1, numMoves+1) {
      fori(i, 0, size)
        fori(j, 0, size) {
          fora(dir, dirs) {
            int nx = i+dir[0], ny = j+dir[1];
            if (0<=nx && nx<size && 0<=ny && ny<size)
              dp[i][j][move] += dp[nx][ny][move-1];
          }
        } 
    }
    return dp[end[0]][end[1]][numMoves];
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  ChessMetric go;
  cout << go.howMany(3, {0,0}, {1,0}, 1) << "\n";
  cout << go.howMany(3, {0,0}, {0,0}, 2) << "\n";
  cout << go.howMany(100, {0,0}, {0,99}, 50) << "\n";
  return 0;
}
