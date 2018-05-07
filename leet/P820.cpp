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

    bool check(string a, string b) {
      int n = a.find(b);
      return n == a.size()-b.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
      int n = SZ(words);
      sort(ALL(words), [](string a, string b) {
        return a.size() > b.size();
      });

      vector<int> dp(n, 0);
      dp[0] = words[0].size() + 1;

      for (int i=1; i<n; ++i) {
        int flag = 0;
        for (int j=0; j<i; ++j) {
          if (check(words[j], words[i])) {
            dp[i] = dp[i-1];
            flag = 1;
            break;
          } 
        }
        if (!flag)
          dp[i] = dp[i-1] + words[i].size() + 1; 
      }
      return dp[n-1];
    }
};