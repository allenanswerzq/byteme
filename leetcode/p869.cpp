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


bool check(int aa) {
  int res = 1;
  while (res < aa) {
  res *= 2;
  }
  return res == aa;
}

class Solution {
public:
  bool reorderedPowerOf2(int aa) {
  vi bb;
  while (aa) {
    bb.pb(aa % 10); 
    aa /= 10;
  }  
  sort(all(bb));
  do {
    // pvi(bb);
    int x = 0;
    if (bb[0] == 0) continue; 
    fori (i, 0, sz(bb)) {
    x *= 10; 
    x += bb[i];
    }
    // trace(x);
    if (check(x)) return 1;
  } while (next_permutation(all(bb)));
  return 0;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p869-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  cout << go.reorderedPowerOf2(1) << endl;
  cout << go.reorderedPowerOf2(10) << endl;
  cout << go.reorderedPowerOf2(16) << endl;
  cout << go.reorderedPowerOf2(24) << endl;
  cout << go.reorderedPowerOf2(64) << endl;

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
