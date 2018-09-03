#include<bits/stdc++.h>
using namespace std;




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

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool dfs(vi& aa, int lo, int hi, int sum, int path) {
  if (lo == hi) {
  if (path > sum - path) return 1;
  return 0;
  }

  if (dfs(aa, lo, hi-1, sum, path + aa[hi]))
  return 1;

  if (dfs(aa, lo + 1, hi, sum, path + aa[lo]))
  return 1;

  return 0;
}

class Solution {
public:
  bool stoneGame(vector<int>& aa) {
  int n = sz(aa);
  int sum = accumulate(all(aa), 0);
  return dfs(aa, 0, n - 1, sum, 0);
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p877-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
