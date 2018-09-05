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

#define vs vector<string>
#define vvs vector<vector<string>>

vs dict;
bool wordBreakRecu(string ss, int ix) {
  int n = sz(ss);
  if (n == 0) return 0;
  if (ix >= n) return 1;
  fora (d, dict) {
    if (ss.substr(ix, sz(d)) == d)
      if (wordBreakRecu(ss, ix + sz(d)))
        return 1;
  } 
  return 0;
}

bool wordBreakBfs(str ss, vs dict) {
  unordered_set<string> st(all(dict));
  deque<int> dq;
  int n = sz(ss);
  int visit[n + 10]; 
  mst(visit, 0);
  dq.push_back(0);
  while (sz(dq)) {
    int idx = dq.front(); dq.pop_front();
    if (visit[idx]) continue;
    visit[idx] = 1;
    fori (j, idx, n) {
      string word = ss.substr(idx, j - idx + 1); 
      if (st.count(word)) {
        dq.push(j + 1);
        if (j + 1 == n) return 1;
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

bool wordBreakDP(string ss) {
  int n, m;
  n = sz(ss);
  if (n == 0) return 0;
  // dp[i] equals true if ss[0...i-1] can be broke.
  int dp[n + 1]; mst(dp, 0);
  fori (i, 1, n + 1) {
    if (dp[i] == 0) {
      if (check(ss.substr(0, i))) 
        dp[i] = 1;
    }

    if (dp[i] == 1) {
      // ss[0...i] can be broke, now we need to check the
      // rest part of the string.
      fori (j, i + 1, n + 1) {
        if (check(ss.substr(i, j-i)))
          dp[j] = 1;  
      }
    }

    if (dp[n]) return 1;
  }
  return 0;
}

class Solution {
public:
  bool wordBreak(string ss, vector<string>& aa) {
    dict = aa;
    // return wordBreakRecu(ss, 0);
    return wordBreakDP(ss);
  }
};

bool test(string ss, vs aa) {
  Solution go;
  int x = go.wordBreak(ss, aa);
  return x;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test("cars", {"car", "ca", "rs"});
  test("leetcode", {"leet", "code"});
  test("applepenapple", {"apple", "pen"});
  test("catsandog", {"cats", "dog", "sand", "and", "cat"});
  return 0;
}
