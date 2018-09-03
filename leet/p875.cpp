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

bool check(ull kk, vi& aa, int hh) {
  int res = 0;
  fora (a, aa) {
  res += (a + kk - 1) / kk;
  }
  return (res <= hh);
}

class Solution {
public:
  int minEatingSpeed(vector<int>& aa, int hh) {
  ull lo = 1, hi = *max_element(all(aa)); 
  // trace(lo, hi);
  while (lo < hi) {
    ull mid = lo + (hi - lo) / 2;
    // trace(lo, hi, mid);
    if (check(mid, aa, hh)) 
    hi = mid;
    else
    lo = mid + 1;
  }
  return lo;
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p875-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  // vi aa = {3, 6, 7, 11};
  // int hh = 8;
  // vi aa = {30, 11, 23, 4, 20};
  // int hh = 6;
  vi aa = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
  int hh = 823855818;
  cout << go.minEatingSpeed(aa, hh);

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
