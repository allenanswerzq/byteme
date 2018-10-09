#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int res;
int n;
vi bb;
// TLE
void dfs(int ix, vl& path) {
  if (ix == n) {
  // pvi(path);
  int t = sz(path);
  // The length of the path shouldn't be less than 3.
  if (t < 3) 
    return;
  // Check.
  fori (i, 1, t) {
    if (path[i] - path[i - 1] != path[1] - path[0])
    return;
  } 
  ++res;
  return;
  } 
  path.pb(bb[ix]);
  dfs(ix + 1, path);
  path.ppb();
  dfs(ix + 1, path);
}

const int N = 1010;
vector<unordered_map<int, int>> dp(N);

class Solution {
public:
  int numberOfArithmeticSlicesDFS(vector<int>& aa) {
  bb = aa;
  n = sz(bb);
  res = 0;
  if (n < 2) return 0; 
  vl path;
  dfs(0, path);     
  return res;
  }

  int numberOfArithmeticSlicesDP(vi aa) {
  int n, res;
  n = sz(aa), res = 0;
  // For each index `i`, maintains a map contains item like 
  // <dist, len> which records the length of one subsequence 
  // that ending at the `ith` index and the diff between 
  // two consecutive numbers is `dist`.
  fori (i, 0, n)
    dp[i].clear();

  fori (i, 0, n) {
    fori (j, 0, i) {
    ll dist = (ll)aa[i] - (ll)aa[j];
    if (dist > INT_MAX || dist < INT_MIN) continue;
    int d = (int)dist;
    int c1 = dp[i][d];
    int c2 = dp[j][d];
    // |a1, a2, ... an| {ai}
    // If we add a new value `ai`, Since the slice at least
    // has 3 numbers, the total result will increased by `n - 1` here.
    res += c2;
    dp[i][d] = c1 + c2 + 1;
    }
  } 
  return res;
  }

  int numberOfArithmeticSlices(vi aa) {
  return numberOfArithmeticSlicesDP(aa);
  }
};

void test(vi aa) {
  Solution go;
  int r = go.numberOfArithmeticSlices(aa);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({2, 2, 3, 4});
  test({2, 4, 6, 8, 10});
  test({1, 2});
  test({0,2000000000,-294967296});
  return 0;
}
