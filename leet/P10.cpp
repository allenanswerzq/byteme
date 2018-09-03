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

int isMatchRecu(string s, string p) {
  int n, m;
  n = sz(s), m = sz(p);
  // Pattern is null, return true only when text is also null.
  if (m == 0) return n == 0;  
  // Whether or not the first character is matched.
  int first = n && (s[0] == p[0] || p[0] == '.');
  if (m >= 2 && p[1] == '*') {
  // '*' stands for zero preceding elements.  
    int x = isMatchRecu(s, p.substr(2));
  // '*' stands for multiple preceding elements.
  int y = first && isMatchRecu(s.substr(1), p); 
    return (x || y);
  } else {
    return first && isMatchRecu(s.substr(1), p.substr(1));
  }
  return -1;
}

int isMatchRecuTwo(string s, string p) {
  int n, m;
  n = sz(s), m = sz(p);
  if (m == 0) return n == 0;
  if (n == 0) {
    fora (c, p)
      if (c != '*')
        return 0;
    return 1;
  }
  if (p[0] == '*') {
  // "*" as the empty char.
    int x = isMatchRecuTwo(s, p.substr(1));   
  // "*" as the any sequence.
    int y = isMatchRecuTwo(s.substr(1), p);
    return (x || y);
  } else if ((s[0] == p[0] || p[0] == '.')) {
    return isMatchRecuTwo(s.substr(1), p.substr(1));  
  } else {
    return false;
  } 
}

// TODO
bool isMatchDP(string s, string p) {
  int n, m;
  n = sz(s), m = sz(p);
  int dp[n+1][m+1];
  mst(dp, 0);
  fori (i, n, -1) {
    fori (j, m, -1) {
    }
  }
  return dp[n][m];
}

bool isMatchTwoDP(string s, string p) {
  int n, m;
  n = sz(s), m = sz(p);
  // dp[i][j] denotes whether the first ith text matches 
  // the jth pattern text or not.
  int dp[n+1][m+1];
  mst(dp, 0);
  fori (i, 0, n+1) {
    fori (j, 0, m+1) {
    }
  }
  return dp[n][m];
}

class Solution {
public:
  bool isMatch(string s, string p) {
    // "*" matches zero or more of the preceding element.
    // return isMatchRecu(s, p);  
    return isMatchDP(s, p);
  }

  bool isMatchTwo(string s, string p) {
    // "*" matches any sequence of characters (including the empty sequence).
    // return isMatchRecuTwo(s, p); 
    return isMatchTwoDP(s, p);
  }
};

int test(string s, string p) {
  Solution go;
  int x = go.isMatch(s, p);
  return x;
}

int test_two(string s, string p) {
  Solution go;
  int x = go.isMatchTwo(s, p);
  return x;
}

#define judge(a, b) assert((a) == (b))

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  
  // Note: invalid input.
  // judge(test("", "*"), 1);
  judge(test("", ".*"), 1);
  judge(test("aa", "a"), 0);
  judge(test("aa", "a*"), 1);
  judge(test("ab", ".*"), 1);
  judge(test("aab", "c*a*b"), 1);
  judge(test("aab", "c******a*b"), 1);
  judge(test("mississippi", "mis*is*p*."), 0);

  // Test_two
  judge(test_two("", ".*"), 0);
  judge(test_two("aa", "a"), 0);
  judge(test_two("aa", "a*"), 1);
  judge(test_two("ab", ".*"), 1);
  judge(test_two("aab", "c*a*b"), 0);
  judge(test_two("aab", "c*****a*b"), 0);
  judge(test_two("mississippi", "mis*is*p*."), 1);
  return 0;
}
