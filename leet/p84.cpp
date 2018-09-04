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

// TODO
// Increasing Stack.
// ref: https://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
class Solution {
public:
  int largestRectangleArea(vector<int>& aa) {
    aa.push_back(0);
    stack<int> stk;
    int res = 0;
    fori (i, 0, sz(aa)) {
      while (!stk.empty() && aa[i] <= aa[stk.top()]) {
        int h = aa[stk.top()]; stk.pop();
        int w = stk.empty() ? -1 : stk.top(); 
        // Compute the area that created by using h as the lowest edge.
        res = max(res, h * (i - w - 1));
        // trace(i, w, res);
      }
      // We still need to compute the area with `i`th bar as the smallest bar.
      // So push it into stack.
      stk.push(i);
    }
    return res;
  }
};

void test(vi aa) {
  Solution go;
  cout << go.largestRectangleArea(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({2,1,5,6,2,3});
  return 0;
}
