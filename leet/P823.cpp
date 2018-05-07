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
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define OUT
#ifdef OUT
#define PR(x) printf x 
#else   
#define PR(x) do { if (0) printf x; } while (0) 
#endif

#define PRT printf
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define FORD(i, a, b) for (int i=(a); i>(b); --i)
#define FORA(e, c) for (auto &e : c)
#define ALL(x) (x).begin(), (x).end()
#define MST(X, v) memset((X), (v), sizeof((X)))
#define LEN(X) strlen(X)
#define VI vector<int>
#define SZ(x) ((int)(x).size())
#define PII pair<int, int>
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define D(x) cerr << #x " is " << (x) << endl
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
      const int MOD = 1000000007;
      int n = a.size();
      sort(ALL(a));
      unordered_map<int, int> mp;
      for (int i=0; i<n; ++i)
        mp[a[i]] = i;

      vector<long> dp(n+1, 0);
      for (int i=0; i<n; ++i) {
        int ans = 1;
        for (int j=0; j<i; ++j) {
          if (a[i] % a[j] == 0) {
            auto it = mp.find(a[i] / a[j]);
            if (it != mp.end())
              // Error
              // ans += (dp[j] * dp[it->second]) % MOD; 
              // Right
              ans = (ans + dp[j] * dp[it->second]) % MOD;
          }
        }
        dp[i] = ans;
      }

      long res = 0;
      for (auto p : dp)
        res += p;
      return  res % MOD;
    }
};