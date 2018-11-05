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

class Solution2 {
public:
  string getHint(string secret, string guess) {
    int dp[256] = {0}, aa = 0, bb = 0;

    fori (i, 0, sz(secret)) {
      if (secret[i] == guess[i]) ++aa;
      else ++dp[secret[i]];
    }

    fori (i, 0, sz(secret)) {
      if (secret[i] != guess[i] && dp[guess[i]]) {
        ++bb;
        --dp[guess[i]];
      }
    }

    return to_string(aa) + "A" + to_string(bb) + "B";
  }
};

class Solution {
public:
  string getHint(string secret, string guess) {
    int dp[256] = {0}, aa = 0, bb = 0;
    fori (i, 0, sz(secret)) {
      if (secret[i] == guess[i]) ++aa;
      else {
        if (dp[secret[i]] < 0) ++bb;
        if (dp[guess[i]] > 0) ++bb;
        dp[secret[i]]++;
        dp[guess[i]]--;
      } 
    } 
    return to_string(aa) + "A" + to_string(bb) + "B";
  } 
};

int main() {
  return 0;
}
