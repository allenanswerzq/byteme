#include<bits/stdc++.h>
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

// Ideas:
// brute force: time complexity O(n3)
// expand around center: time complexity O(n2)
// dp: time complexity O(n2)

class Solution {
public:
  string longestPalindrome(string ss) {
  int n = sz(ss);
  string res = "";
  if (n == 0) return res;
  int dp[n][n]; mst(dp, 0);
  ford (i, n - 1, -1) {
    fori (j, i, n) {
    dp[i][j] = ss[i] == ss[j] && (j - i + 1 <= 3 || dp[i + 1][j - 1]);
    if (dp[i][j] && (res == "" || j - i + 1 > sz(res))) {
      res = ss.substr(i, j - i + 1);
    }
    } 
  }
  return res;
  }

  string longestPalindrome1(string ss) {
  int n = sz(ss);
  if (n < 2) return ss;
  string res = "";
  int lo = 0, maxLen = 0;
  fori (i, 0, n - 1) {
    int la = expandAroundCenter(ss, i, i);
    int lb = expandAroundCenter(ss, i, i + 1);

    if (la > maxLen) {
    maxLen = la;
    lo = i - la / 2;
    }

    if (lb > maxLen)  {
    maxLen = lb;
    lo = i - lb / 2 + 1;
    }

    // trace(i, la, lb, lo, maxLen);
  }
  return ss.substr(lo, maxLen);
  }

  int expandAroundCenter(string& ss, int left, int right) {
  int lo = left, hi = right;
  while (lo >= 0 && hi < ss.size() && ss[lo] == ss[hi]) {
    lo--;
    hi++;
  }
  return hi - lo - 1;
  }
};

void test(string inp, string right) {
  Solution go;
  string res = go.longestPalindrome1(inp);
  trace(inp, res, right);
  assert(res == right);
}

int main() {
  test("babad", "bab");
  test("cbbd", "bb");
  test("abcba", "abcba");
  return 0;
}
