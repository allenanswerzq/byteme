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

class Cafeteria {
public:
  string pad(int val) {
    if (val < 10) return "0" + to_string(val);
    return "" + to_string(val);
  }

  string latestTime(vi offset, vi walk, vi drive) {
    int n = sz(offset);
    int goal = 14 * 60 + 30;
    int ans = 0;
    fori(i, 0, n) {
      int o = offset[i], w = walk[i], d = drive[i];
      int off = 0;
      // Note: If i take this time's bus, its too early
      // It i take next time's bus, its too early or just right
      // Then take the next one.
      // Also can simply write like this:
      // while (off + o + 10 + d <= goal)
      while (off + o < goal - d  && off + o + 10 <= goal - d ) 
        off += 10;
      // cout << off << '\n';
      ans = max(ans, off + o - w);
    }
    if (ans / 60 >= 13) {
      return "0" + to_string(ans / 60 - 12) + ":" + pad(ans % 60);
    }
    return pad(ans / 60) + ":" + pad(ans % 60);
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  Cafeteria go;
  vi off = {6,9};
  vi walk =  {9,10};
  vi drive = {120,121};
  cout << go.latestTime(off, walk, drive) << '\n';

  off = {0,1,2,3,4,5,6,7,8,9};
  walk = {11,11,11,11,11,11,11,11,11,11};
  drive = {190,190,190,190,190,190,190,190,190,190};
  cout << go.latestTime(off, walk, drive) << '\n';

  off ={7,4,0,0,2,1,6,7,7,0,8,6,0,5,0,6,7,9,0,2,4,8,4,7, 
        9,2,4,4,3,1,4,5,8,8,2,5,7,8,7,5,6,8,8,0,1,3,5,0,8};
  walk = {26,14,1,4,16,28,16,6,4,5,21,18,5,2,21,21,28,22,5,22,26,16,14, 
          19,19,19,4,12,24,4,30,16,28,20,25,2,30,18,4,6,9,22,8,3,7,29,8,30,6};
  drive = {151,264,280,89,63,57,15,120,28,296,76,269,90,106,31,222, 
          291,52,102,73,140,248,44,187,76,49,296,106,54,119,54,283,263, 
        285,275,127,108,82,84,241,169,203,244,256,109,288,9,262,103};
  cout << go.latestTime(off, walk, drive) << '\n';
  return 0;
}
