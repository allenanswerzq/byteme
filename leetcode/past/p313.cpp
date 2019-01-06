#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

// #define LOCAL_FILE

#define vi vector<int>
// x = min(primes(0) ** a, primes(1) ** b, ... , primes(k) ** (a + k - 1))
class Solution {
public:
  int nthSuperUglyNumber(int kk, vector<int>& primes) {
  int n = sz(primes);
  vi idx(n, 0);
  vi dp(kk, (1<<30)); 
  dp[0] = 1;
  fori (i, 1, kk) {
    fori (j, 0, n) 
    dp[i] = min(dp[i], dp[idx[j]] * primes[j]); 

    fori (j, 0, n) {
    if (dp[i] == dp[idx[j]] * primes[j]) 
      ++idx[j];
    }  
     
  }
  return dp[kk-1];
  }
};

int main() {
 
  return 0;
}
