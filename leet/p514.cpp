#include<bits/stdc++.h>
using namespace std;


const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

unordered_map<string, int> mp;

int dfs(string ring, string key, int ix) {
  int n, res, a, b, ra, rb;
  char c;
  string sa, sb;

  if (ix == sz(key)) return 0;
  if (mp.count(ring + key + to_string(ix))) 
    return mp[ring + key + to_string(ix)];

  n = sz(ring);
  c = key[ix];

  a = dist(ring.begin(), find(all(ring), c));
  b = dist(ring.rbegin(), find(rall(ring), c));

  sa = ring.substr(a) + ring.substr(0, a);
  sb = ring.substr(b) + ring.substr(0, b);

  // cout << a << " " << b << " " << "\n";
  // cout << sa << " " << sb << " " << "\n";

  ra = 1 + a + dfs(sa, key, ix + 1);
  rb = 1 + n - b + dfs(sb, key, ix + 1);
  res = min(ra, rb);

  mp[ring + key + to_string(ix)] = res; 
  return res;
}

int findRotateStepsDP(string ring, string key) {
  int n, res, m;
  n = sz(ring);
  m = sz(key);
  int dp[m + 1][n];
  mst(dp, 0);
  
}

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    // return dfs(ring, key, 0);    
    return findRotateStepsDP(ring, key);
  }

};

void test(str inp, str key) {
  Solution go;
  int r = go.findRotateSteps(inp, key);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test("godding", "gd");
  return 0;
}
