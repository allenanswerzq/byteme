#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vs dict;

bool wordBreakRecu(string s, int ix) {
  int n = sz(s);
  if (n == 0) return 0;
  if (ix >= n) return 1;
  fora (d, dict) {
    if (s.substr(ix, sz(d)) == d)
      if (wordBreakRecu(s, ix + sz(d)))
        return 1;
  } 
  return 0;
}

bool wordBreakBfs(str s, vs dict) {
  queue<int> q;
  int n = sz(s);
  int visit[n + 10];
  mst(visit, 0);
  q.push(0);
  while (sz(q)) {
    int start = q.fr(); q.pop();
    if (visit[start]) continue;
    visit[start] = 1;
    fori (j, start, n) {
      str w = s.substr(start, j - start + 1); 
      if (dict.find(w) != dict.end()) {
        q.push(j + 1);
        if (j + 1 == n)
          return 1;
      }
    }
  }
  return 0;
}

bool check(string inp) {
  fora (d, dict) {
    if (d == inp)
      return 1;
  }
  return 0;
}

bool wordBreakDP(string s) {
  int n, m;
  n = sz(s);
  if (n == 0) return 0;
  // dp[i] equals true if s[0...i-1] can be broke.
  int dp[n + 1];
  mst(dp, 0);
  fori (i, 1, n + 1) {
    if (dp[i] == 0) {
      if (check(s.substr(0, i))) dp[i] = 1;
    }

    if (dp[i] == 1) {
      // s[0...i] can be broke, now we need to check the
      // rest part of the string.
      fori (j, i+1, n+1) {
        if (check(s.substr(i, j-i)))
          dp[j] = 1;  
      }
    }
    if (dp[n]) return 1;
  }
  return 0;
}

class Solution {
public:
  bool wordBreak(string s, vector<string>& aa) {
    dict = aa;
    // return wordBreakRecu(s, 0);
    return wordBreakDP(s);
  }
};

bool test(string s, vs aa) {
  Solution go;
  int x = go.wordBreak(s, aa); 
  return x;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  judge(test("cars", {"car", "ca", "rs"}), 1);
  judge(test("leetcode", {"leet", "code"}), 1);
  judge(test("applepenapple", {"apple", "pen"}), 1);
  judge(test("catsandog", {"cats", "dog", "sand", "and", "cat"}), 0);
  return 0;
}
