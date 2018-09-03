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

class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>>& aa) {
  int m = sz(aa), n = sz(aa[0]);
  vvi res (n, vi(m, 0));
  fori (i, 0, n) {
    fori (j, 0, m) 
    res[i][j] = aa[j][i];
  } 
  return res;
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p867-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
