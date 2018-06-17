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
#include <unistd.h>
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

ll cnt[15][15][15][15];
ll comb[60][60];
ll height;

class ChristmasTree
{
public:

  ll dp(int level, int r, int g, int b) {
    // Note:  returns 1 here.
    if (level == height + 1) return 1;

    ll ret = cnt[level][r][g][b];
    if (ret != -1) return ret;

    ll ans = 0;

    // Case 1: fill this level with only one color.
    if (r >= level) ans += dp(level+1, r-level, g, b);
    if (g >= level) ans += dp(level+1, r, g-level, b); 
    if (b >= level) ans += dp(level+1, r, g, b-level);

    // Case 2: fill this level with two colors.
    if (level % 2 == 0) {
      int k = level / 2;
      ll c = comb[level][k]; 
      if (r >=k && g >= k) ans += dp(level+1, r-k, g-k, b) * c;
      if (r >=k && b >= k) ans += dp(level+1, r-k, g, b-k) * c;
      if (g >=k && b >= k) ans += dp(level+1, r, g-k, b-k) * c;
    }

    // Case 3: fill this level with three colors.
    if (level % 3 == 0) {
      int k = level / 3;
      ll c = comb[level][k] * comb[level-k][k];
      if (r>=k && g>=k && b>=k) ans += dp(level+1, r-k, g-k, b-k) * c; 
    }

    cnt[level][r][g][b] = ans;

    return ans;
  }

  ll decorationWays(int h, int red, int green, int blue) {
    height = h;
    memset(cnt, -1, sizeof(cnt));

    // c(n, k) = c(n-1, k-1) + c(n-1, k)
    comb[0][0] = 1;
    fori(n, 0, 60)
      fori(k, 0, n+1)
        comb[n][k] = (k == 0) ? 1 : comb[n-1][k-1] + comb[n-1][k];

    return dp(1, red, green, blue);
  } 
  
};

// Expected:
// 1911899254684272

// Received:
// 1911898796777794

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  ChristmasTree go;
  cout << go.decorationWays(2, 1, 1, 1) << "\n";
  cout << go.decorationWays(8, 1, 15, 20) << "\n";
  // This case is wrong.
  cout << go.decorationWays(10, 50, 50, 50) << "\n";
  return 0;
}
