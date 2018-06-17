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

class Jewelry {
public:
  #define MAX_SUM 31000
  ll cache[31][31];
  vi values;
  int n;
  ll combination(int n, int k);
  vi ways(int lo, int hi);
  ll howMany(vi aa) {
    values = aa;
    n = sz(aa);
    mst2(cache, 31, 31, 0);
    sort(all(values));
    long ret = 0;
    fori(i, 0, n) {
      int sizeg = 1;
      int idx = i;
      while(idx+1<n && values[idx] == values[idx+1])
        ++idx, ++sizeg;
      vi waysBelow = ways(0, i-1);
      fori(k, 1, sizeg+1) {
        vi waysAbove = ways(i+k, n-1);
        ll x = k*values[i]; // Total values will be assigned to Bob.
        fori(sum, x, MAX_SUM) {
          ret += combination(sizeg, k) * waysBelow[sum - x] * waysAbove[sum];
        }
      }
      i = idx;
    }
    return ret;
  }
};

 vi Jewelry::ways(int lo, int hi) {
  vi dp(MAX_SUM, 0); 
  dp[0] = 1;
  if (lo > hi) return dp;
  fori(i, lo, hi+1)
    ford(j, MAX_SUM, 0) {
      // Fuck, just a small typo cost me a lot of time.
      // if (j >= values[j])
      if (j >= values[i])
        dp[j] += dp[j - values[i]];
    } 
  return dp;
 } 

// The number of ways to choose k numbers from total n numbers.
// Math combination. C(n, k) = C(n-1, k-1) + C(n-1, k).
ll Jewelry::combination(int n, int k) {
  if (cache[n][k] != 0)
      return cache[n][k];
  if (n==k || k==0)
      return 1;
  // Fuck, Pay attention to type, man...
  // cache[n][k] = cache[n-1][k-1] + cache[n-1][k];
  cache[n][k] = combination(n-1, k-1) + combination(n-1, k);
  return cache[n][k];
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  Jewelry go;
  vi aa = {1, 2, 5, 3, 4, 5};
  cout << go.howMany(aa) << "\n";
  aa = {1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000};
  cout << go.howMany(aa) << "\n";
  return 0;
}
