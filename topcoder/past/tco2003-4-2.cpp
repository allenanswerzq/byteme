#include<bits/stdc++.h>
using namespace std;

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
    mst(cache, 0);
    sort(all(values));
    long ret = 0;
    fori (i, 0, n) {
      int sizeg = 1;
      int idx = i;
      while (idx + 1 < n && values[idx] == values[idx + 1])
        ++idx, ++sizeg;
      vi waysBelow = ways(0, i- 1);
      fori (k, 1, sizeg+1) {
        vi waysAbove = ways(i + k, n - 1);
        // Total values will be assigned to Bob.
        ll x = k * values[i];
        fori (sum, x, MAX_SUM) {
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
  fori (i, lo, hi+1)
    ford (j, MAX_SUM, 0) {
      // Fuck, just a small typo cost me a lot of time.
      // if (j >= values[j])
      if (j >= values[i]) dp[j] += dp[j - values[i]];
    }
  return dp;
 }

// The number of ways to choose k numbers from total n numbers.
// Math combination. C(n, k) = C(n-1, k-1) + C(n-1, k).
ll Jewelry::combination(int n, int k) {
  if (cache[n][k] != 0) return cache[n][k];
  if (n == k || k == 0) return 1;
  // Fuck, Pay attention to type, man...
  // cache[n][k] = cache[n-1][k-1] + cache[n-1][k];
  cache[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
  return cache[n][k];
}

void test(vi aa) {
  Jewelry go;
  auto r = go.howMany(aa);
  output(r);
}

int main() {
  test({1, 2, 5, 3, 4, 5});
  test({1000,1000,1000,1000,1000,
       1000,1000,1000,1000,1000,
       1000,1000,1000,1000,1000,
       1000,1000,1000,1000,1000,
       1000,1000,1000,1000,1000,
       1000,1000,1000,1000,1000});
  return 0;
}
