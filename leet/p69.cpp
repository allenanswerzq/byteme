#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
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

class Solution {
public:
  // Integer square root
  // https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
  // newton's iterative approach
  int mySqrt1(int n) {
  // Must be long long becasue below operation x * x
  ll x = n;
  while (x * x > n) {
    x = (x + n / x) / 2;
  }
  return x; 
  }

  // Binary search approach
  int mySqrt(int n) {
  if (n <= 1) return n;
  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (mid > n / mid) hi = mid;
    else lo = mid + 1;
  }
  return lo - 1;
  }
};

void test(int x) {
  Solution go;
  int ret = go.mySqrt(x);
  trace(x, ret);
}

int main(int argc, char** argv) {
  test(0);
  test(1);
  test(2);
  test(8);
  test(INT_MAX);
  test(1579205274);
  return 0;
}
