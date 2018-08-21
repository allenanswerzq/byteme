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


bool prime(int aa) {
  if (aa == 1) return 0;
  // fori (i, 2, sqrt(aa + 1))
  for (int i=2; i*i <= aa; ++i)
    if (aa % i == 0)
      return 0;
  return 1; 
}

bool palind(int aa) {
  string s = to_string(aa);
  int lo = 0, hi = sz(s)-1;
  while (lo < hi) {
    if (s[lo] != s[hi]) return 0;
    ++lo; --hi;
  }
  return 1;
}

class Solution {
public:
  int primePalindrome(int aa) {
    uint up = (1 << 31);
    // trace(aa, up);
    fori (i, aa, up) {
      // trace(aa, i, prime(i));
      if (prime(i) && palind(i))
        return i;  
    }
    return 0;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p866-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  cout << go.primePalindrome(1) << endl;
  cout << go.primePalindrome(2) << endl;
  cout << go.primePalindrome(6) << endl;
  cout << go.primePalindrome(8) << endl;
  cout << go.primePalindrome(11) << endl;
  cout << go.primePalindrome((int)(1e8)) << endl;
  cout << go.primePalindrome(9989900) << endl;

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
