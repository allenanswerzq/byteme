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
  bool lemonadeChange(vector<int>& aa) {
  int a, b, c;
  a = b = c = 0;
  fori (i, 0, sz(aa)) {
  // trace(i);
  if (aa[i] == 5) ++a;
  else if (aa[i] == 10) {
  if (a <= 0) return 0;
  ++b;
  --a;
  } else if (aa[i] == 20) {
  if (a < 1 && b > 1) return 0;
  if (a < 3 && b < 1) return 0; 

  if (b == 0 && a>=3) {
    a -= 3;
  } else if (b > 0) {
    --b;
    --a;
  }
  }
  }     
  return 1;
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p860-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  // vi aa = {5,5,10,10,20}; 
  // vi aa = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
  cout << go.lemonadeChange(aa) << endl;

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
