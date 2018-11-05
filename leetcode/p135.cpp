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

class Solution {
public:
  int candy(vector<int> &aa) {
    int n = aa.size();
    if (n <= 1) return n;

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
      if (aa[i] > aa[i-1])
        dp[i] = dp[i-1] + 1;

    for (int i = n - 1; i > 0 ; i--)
      if (aa[i-1] > aa[i])
        dp[i-1] = max(dp[i] + 1, dp[i-1]);

    int ret = 0;
    for (int i = 0; i < n; i++) {
      ret += dp[i];
    }

    return ret;
  }
};

int main() {
   return 0;
}
