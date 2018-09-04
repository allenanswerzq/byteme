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


typedef pair<int, int> pii
typedef vector<vector<char>> vvc

bool check(int ux, int uy, int bx, int by) {
  fori (i, ux, bx + 1) {
    fori (j, uy, by + 1)
      if (gg[i][j] != '1')
      return 0;    
    }
  return 1;
}

// Brute force method.
// Time: O(n^2 * m^2)
int maximalRectangleOne(vvc& gg) {
  if (sz(gg) <= 0) return 0;
  int n, m;
  n = sz(gg);
  m = sz(gg[0]);
  int res = 0;
  fori(ux, 0, n)
    fori(uy, 0, m)
      fori(bx, 0, n)
        fori(by, 0, m) {
          if (check(ux, uy, bx, by)) {
            int area = (bx - ux + 1) * (by - uy + 1);
            res = max(res, area); 
          }
        }
  return res;
}

int area(int ux, int uy, int bx, int by) {
  return (bx - ux + 1 ) * (by - uy + 1);
}

pii bottom_address(int ux, int uy) {
  // How big area that contains only one can we reach 
  // starting with uppper corner `(ux, uy).
  int n, m;
  int bx, by;
  int x, y;
  int y_max;

  n = sz(gg), m = sz(gg[0]);
  bx = ux, by = uy;
  y_max = m;
  x = ux;
  while (x < n && gg[x][uy] == '1') {
    int y = uy;
    while(y < y_max && gg[x][y] == '1') ++y;
    y_max = min(y_max, y);
    if (area(ux, uy, x, y - 1) > area(ux, uy, bx, by)) {
      bx = x;
      by = y - 1;
    }
    ++x;
  }

  if (gg[bx][by] == '1') return pii(bx, by);
  else return pii(-1, -1);
}

// Time: O(n^2 * m^2)
int maximalRectangleTwo(vvc& gg) {
  int n, m;
  int res = 0;

  if (sz(gg) <= 0) return 0;
  n = sz(gg), m = sz(gg[0]);

  fori (ux, 0, n)
    fori (uy, 0, m) {
      pii b = bottom_address(ux, uy);
      int bx = b.fi, by = b.se;
      if (bx == -1 && by == -1) continue;
      int tmp = area(ux, uy, bx, by);
      trace(ux, uy, bx, by, tmp);
      res = max(res, tmp);
    }
  return res;
}

void update_dp(int *dp, int n, int y) {
  fori (x, 0, n) {
    if (gg[x][y] == '1') dp[x] += 1;
    else dp[x] = 0;
  }
}

pii bottom_address_dp(int *dp, int ux, int uy) {
  // How big all ones area can we reach starting with uppper corner `(ux, uy).
  int n, m, bx, by, x, y, y_max;

  n = sz(gg), m = sz(gg[0]);
  bx = ux, by = uy;
  y_max = m;
  x = ux;
  while (x < n && gg[x][uy] == '1') {
    int y = uy + dp[x];
    y = min(y_max, y);
    y_max = y;
    if (area(ux, uy, x, y-1) > area(ux, uy, bx, by)) {
      bx = x;
      by = y-1;
    }
    ++x;
  }

  if (gg[bx][by] == '1') return pii(bx, by);
  else return pii(-1, -1);
}

// Time: O(n^2 * m)
int maximalRectangleThree(vvc& gg) {
  // DP method.
  if (sz(gg) <= 0) return 0;
  int n = sz(gg), m = sz(gg[0]);
  int res = 0;

  int dp[n];
  mst(dp, 0);

  // As long as our search can cover all the sub matrices, we can get the 
  // correct answer, no matter what order we are searching here.
  ford (uy, m - 1, -1) {
    update_dp(dp, n, uy); 
    fori (ux, 0, n) {
      pii b = bottom_address_dp(dp, ux, uy);
      int bx = b.fi, by = b.se;
      if (bx == -1 && by == -1) continue;
      int tmp = area(ux, uy, bx, by);
      trace(ux, uy, bx, by, tmp);
      res = max(res, tmp);
    }
  }
  return res;
}

int largestRectangleArea(vector<int>& aa) {
  aa.push_back(0);
  stack<int> stk;
  int res = 0;
  fori (i, 0, sz(aa)) {
    while(!stk.empty() && aa[i] <= aa[stk.top()]) {
      int h = aa[stk.top()]; stk.pop();
      int w = stk.empty() ? -1 : stk.top(); 
      res = max(res, h * (i - w - 1));
    }
    // We still need to compute the area with `i`th bar as the smallest bar.
    // So push it into stack.
    stk.push(i);
  }
  return res;
}

// Time: O(m * n)
int maximalRectangleFour(vvc& gg) {
  // DP method.
  if (sz(gg) <= 0) return 0;
  int n = sz(gg), m = sz(gg[0]);
  int res = 0;

  int dp[n]; mst(dp, 0);
  
  ford (uy, m - 1, -1) {
    update_dp(dp, n, uy); 

    vi tmp;
    fori (i, 0, n) 
      tmp.push_back(dp[i]); 
    res = max(res, largestRectangleArea(tmp));  
  }
  return res;
}

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& aa) {
  // return maximalRectangleOne(aa);  
  // return maximalRectangleTwo(aa); 
  // return maximalRectangleThree(aa);
  return maximalRectangleFour(aa);
  }
};

void test(vector<vector<char>> aa) {
  Solution go;
  cout << go.maximalRectangle(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  vector<vector<char>> aa = {
      {'1','0','1','0','0'},
      {'1','0','1','1','1'},
      {'1','1','1','1','1'},
      {'1','0','0','1','0'}};

  test(aa);
  test({{'0'}});
  test({{'0', '0'}});

  return 0;
}
