#include <bits/stdc++.h>
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

// Given a sorted integer array where the range of elements are [0, 99] 
// inclusive, return its missing ranges.
// For example, given [0, 1, 3, 50, 75], 
// return [“2”, “4->49”, “51->74”, “76->99”]

#define vi vector<int>
#define vs vector<string>

// TODO
class Solution {
public:
  vs missingRange(vi& aa, int lo, int hi) {
    vs ret;
    aa.insert(aa.begin(), lo - 1);
    aa.insert(aa.end(), hi + 1);
    fori (i, 0, sz(aa) - 1) {
      int ss = aa[i], tt = aa[i + 1]; 
      // trace(ss, tt);
      if (tt - ss + 1 == 3) {
        ret.push_back(to_string(ss + 1));
      } else if (tt - ss + 1 > 3) {
        ret.push_back(to_string(ss + 1) + "->" + to_string(tt - 1));
      }
    }
    return ret;
  }
};

void test(vi aa, int lo, int hi) {
  Solution go;
  vs ret = go.missingRange(aa, lo, hi);
  pvi(ret);
}

int main() {
  test({1}, 0, 99);
  test({}, 0, 99);  
  test({0, 1, 3, 50, 75}, 0, 99);
  return 0;
}
