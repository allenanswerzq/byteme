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
#define prt(x, n) fori(i, 0, n) cout << x[i] << " "; cout << "\n"
#define prt2(x, n, m) fori(i, 0, n) {fori(j, 0, m) cout << x[i][j] << " "; \
        cout << "\n"; } cout << "\n"
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

class StripePainter
{
public:
  // dp[i][j] denotes the mininum number of paints needed 
  // if we paint in the range of i...j
  int dp[54][54];
  int minStrokes(string stripes) {
    mst2(dp, 54, 54, 0);
    int n = sz(stripes);
    fori(i, 0, n)
      dp[i][i] = 1;

    fori(size, 1, n) {
      fori(i, 0, n-size) {
        if (stripes[i] == stripes[i+size])
          dp[i][i+size] = dp[i][i+size-1];
        else {
          int t = 0x30303030;
          fori(k, 0, size) 
            t = min(t, dp[i][i+k] + dp[i+k+1][i+size]);
          dp[i][i+size] = t;
        }
      }
      prt2(dp, n, n);
    }
    return dp[0][n-1];
  }  
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  StripePainter go;
  cout << go.minStrokes("RGBGR") << "\n";
  // cout << go.minStrokes("RGRG") << "\n";
  // cout << go.minStrokes("ABACADA") << "\n";
  return 0;
}
