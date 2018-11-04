#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

#define vi vector<int>
#define vvi vector<vi>

// 1) If last characters of two strings are same, nothing much to do. 
// Ignore last characters and get count for remaining strings. So we recur for 
// lengths m-1 and n-1.

// 2) Else (If last characters are not same), we consider all operations 
// on ‘str1’, consider all three operations on last character of first string, 
// recursively compute minimum cost for all three operations and 
// take minimum of three values.
//  Insert: Recur for m and n-1
//  Remove: Recur for m-1 and n
//  Replace: Recur for m-1 and n-1

class Solution {
public:
  // ref: http://www.stanford.edu/class/cs124/lec/med.pdf 
  int minDistance(string w1, string w2) {
    int n1 = w1.size(), n2 = w2.size();
    int dp[n1 + 1][n2 + 1];
    for (int i = 0; i <= n1; ++i) dp[i][0] = i;
    for (int i = 0; i <= n2; ++i) dp[0][i] = i;
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        if (w1[i - 1] == w2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j - 1], 
                     min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
      }
    }
    return dp[n1][n2];
  }
};

int main() {
  return 0;
}
