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
#define pvi(x) fora(r, x) cout << r << ' '; cout << ' '
#define cerr(x) cerr << #x " is " << (x) << endl
#define mst(x, n, v) fori(i, 0, n) x[i] = v
#define mst2(x, n, m, v) fori(i, 0, n) fori(j, 0, m) x[i][j] = v
#define mst3(x, n, m, c, v) \
        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class LargestCircle {
public:
  vs grid;
  int height, width;
  int dist(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
  }

  bool check(int x, int y, int r) {
    int rs = r * r;
    fori(i, 0, height) {
      fori(j, 0, width) {
        int d1 = dist(i, j, x, y);
        int d2 = dist(i+1, j, x, y);
        int d3 = dist(i, j+1, x, y);
        int d4 = dist(i+1, j+1, x, y);
        if (d1>=rs && d2>=rs && d3>=rs && d4>=rs) continue;
        if (d1<=rs && d2<=rs && d3<=rs && d4<=rs) continue;
        if (grid[i][j] == '#')
          return false;
      }
    } 
    return true;
  }

  int radius(vs aa) {
    grid = aa;
    height = sz(grid);
    width = sz(grid[0]);
    int res = 0;
    fori(i, 1, height) 
      fori(j, 1, width) {
        int r_max = min(min(i, height-i), min(j, width-j));
        fori(r, 1, r_max+1)
          // Use <i,j> as circle center point and r as radius.
          if (check(i, j, r))
            res = max(res, r);
      } 
    return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  vs grid =  { "############",
    "###......###",
    "##.######.##",
    "#.########.#",
    "#.##..####.#",
    "#.##..####.#",
    "#.########.#",
    "#.########.#",
    "#.########.#",
    "##.######.##",
    "###......###",
    "############" };
    LargestCircle go;
    cout << go.radius(grid) << '\n';
  return 0;
}
