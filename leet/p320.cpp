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

// Write a function to generate the generalized abbreviations of a word.

// Example:

// Given word = "word", return the following list (order does not matter):

// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


#define vs vector<string>
class Solution {
public:
  vs generateAbberviations(string word) {
    vs res;
    int n = sz(word);
    fori (i, 0, (1 << n)) {
      string tmp = "";
      int cnt = 0;
      fori (j, 0, n) {
        if (((i >> j) & 1) == 1) ++cnt;
        else {
          if (cnt) {
            tmp += to_string(cnt);
            cnt = 0;
          } 
          tmp += word[j]; 
        }
      } 
      if (cnt > 0) tmp += to_string(cnt);
      // trace(i, tmp);
      res.push_back(tmp);
    } 
    return res;
  }
};

void test(string inp) {
  Solution go;
  vs res = go.generateAbberviations(inp);
  pvi(res);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  
  test("word");

  return 0;
}
