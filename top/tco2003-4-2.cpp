#include<bits/stdc++.h>
using namespace std;

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
