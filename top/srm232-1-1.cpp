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
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class WordFind {
public:
  vs grid;
  vs wl;
  vs findWords(vs aa, vs bb) {
    grid = aa;
    wl = bb;
    int n = sz(grid), m=sz(grid[0]), d=sz(wl);
    vs res;
    fori(i, 0, d) {
      string w = wl[i];
      fori(k, 0, n) {
        int flag = 0;
        fori(j, 0, m) {
          if (grid[k][j] == w[0]) {
            fori(h, 0, 3) {
              int r = 0;
              // Go right
              if (h == 0) 
                while(r+j<m && grid[k][r+j] == w[r]) ++r;
              // Go down
              if (h == 1)
                while(k+r<n && grid[k+r][j] == w[r]) ++r;
              // Go down and right
              if (h == 2)
                while(k+r<n && grid[k+r][j+r] == w[r]) ++r;
              if (r == sz(w)) { 
                res.pb(to_string(k) + " " + to_string(j));
                flag = 1;
                break;
              }
            }
            if (flag) break;
          }
        }
        if (flag) break;
      }
    }
    return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  WordFind go;
  vs grid = {"TEST",
            "GOAT",
            "BOAT"};
  vs wl = {"GOAT", "BOAT", "TEST"};
  vs res = go.findWords(grid, wl);
  pvi(res);

  grid = {"EASYTOFINDEAGSRVHOTCJYG",
          "FLVENKDHCESOXXXXFAGJKEO",
          "YHEDYNAIRQGIZECGXQLKDBI",
          "DEIJFKABAQSIHSNDLOMYJIN",
          "CKXINIMMNGRNSNRGIWQLWOG",
          "VOFQDROQGCWDKOUYRAFUCDO",
          "PFLXWTYKOITSURQJGEGSPGG"};
  wl = {"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"};
  res = go.findWords(grid, wl);
  pvi(res);
  return 0;
}
