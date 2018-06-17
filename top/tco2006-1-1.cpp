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
#include "../common.h"
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
#define prt(x, n) fori(i, 0, n) cout << x[i] << " "; cout << "\n"
#define prt2(x, n, m) fori(i, 0, n) {fori(j, 0, m) cout << x[i][j] << " "; \
        cout << "\n"; } cout << "\n"
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

class SeparateConnections
{
public:
  int dp[1<<18];
  int howMany(vs mat) {
    int n = sz(mat);
    cout << n << "\n";
    int n2 = 1 << n;
    mst(dp, 1<<18, 0);
    dp[0] = 0;
    fori(i, 1, n2) {
      vi rm = rmo(i);
      int lowest = rm[0], idx = rm[1];
      cout << lowest << " " << idx << "\n";
      // Case 1: The lowest node is not communicate at all
      dp[i] = dp[i ^ lowest];
      // Case 2: The lowest node is communicating with some nodes
      fori(k, idx+1, n) {
        if ((i & (1<<k)) && mat[idx][k] == 'Y' )
          dp[i] = max(dp[i], dp[i ^ lowest ^ (1 << k)] + 2);
      }
    }
    return dp[n2 - 1];
  }  
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  vs aa = {
    "NYYYY",
    "YNNNN",
    "YNNNN",
    "YNNNN",
    "YNNNN"
    };
SeparateConnections go;
cout << go.howMany(aa) << "\n";
  return 0;
}
