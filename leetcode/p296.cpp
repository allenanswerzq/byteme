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

// A group of two or more people wants to meet and minimize the total travel distance. 
// You are given a 2D grid of values 0 or 1, 
// where each 1 marks the home of someone in the group. 
// The distance is calculated using Manhattan Distance, 
// where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

// For example, given three people living at (0,0), (0,4), and (2,2):

// 1 - 0 - 0 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
// The point (0,2) is an ideal meeting point, 
// as the total travel distance of 2+2+2=6 is minimal. So return 6.

// Hint:
// Try to solve it in one dimension first. How can this solution apply to the two dimension case?

#define vi vector<int>
#define vvi vector<vi>

int go(vi& aa) {
  int ret = 0;
  sort(all(aa)); 
  int lo = 0, hi = sz(aa) - 1;
  while (lo < hi) {
    ret += aa[hi] - aa[lo];
    --hi; ++lo;
  }
  return ret;
}

class Solution {
public:
  int minTotalDistance(vvi& gg) {
    vi rows, cols;
    fori (i, 0, sz(gg)) {
      fori (j, 0, sz(gg[0])) {
        if (gg[i][j] == 1) {
          rows.push_back(i);
          cols.push_back(j);
        }
      } 
    }
    return go(rows) + go(cols);
  }
};

int main() {
  return 0;
}
