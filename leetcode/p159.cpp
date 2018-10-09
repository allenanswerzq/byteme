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

// Given a string S, find the length of the longest substring T that contains 
// at most two distinct characters.
// For example,
// Given S = “eceba”,
// T is “ece” which its length is 3.

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string ss) {
    int ret = 0, lo = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < ss.size(); ++i) {
      ++mp[ss[i]];
      while (mp.size() > 2) {
        if (--mp[ss[lo]] == 0) 
          mp.erase(ss[lo]);
        ++lo;
      }
      ret = max(ret, i - lo + 1);
    }
    return ret;
  }
};

int main(int argc, char** argv) {
  return 0;
}
