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
  int shortestSubarray(vector<int>& aa, int kk) {
    int n = sz(aa);
    if (n == 0) return -1;
    int res = (1 << 20);
    ll pre_sum = 0;
    vector<pair<ll, int>> sums;
    sums.eb(0, -1);
    fori (i, 0, n) {
      pre_sum += aa[i];
      int pos = upper_bound(all(sums), mk(pre_sum - kk, 1<<20)) - sums.begin();
      --pos;
      if (pos >= 0) 
        res = min(res, i - sums[pos].se);
      trace(pre_sum, pos, res);
      while (sz(sums) && sums.back().fi >= pre_sum) 
        sums.ppb();
      sums.pb({pre_sum, i});
    }
    return res == (1<<20) ? -1 : res;
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p862-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  vi aa = {2,-1,2};
  int kk = 3; 
  // vi aa = {1,2};
  // int kk = 4; 
  cout << go.shortestSubarray(aa, kk) << endl;

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
