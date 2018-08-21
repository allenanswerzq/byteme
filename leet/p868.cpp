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
  int binaryGap(int aa) {
    int res = 0;
    int lo, hi;
    lo = -1;
    hi = 0;
    while (aa) {
      if (aa & 1) {
        if (lo == -1) lo = hi; 
        else {
          res = max(res, hi - lo);
          lo = hi;
        }
      }
      ++hi;
      aa >>= 1;
    }     
    return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p868-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  // int aa = 22;
  // int aa = 5;
  // int aa = 6;
  int aa = 8;
  cout << go.binaryGap(aa) << endl;

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
