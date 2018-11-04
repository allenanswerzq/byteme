#include<bits/stdc++.h>
using namespace std;

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

#define ll long long

class Solution {
public:
  double myPow(double x, int n) {
    ll t = n;
    if (t < 0) {
      x = 1 / x;
      t = labs(t);
    }
    double res = 1.0;
    while (t) {
      if (t % 2) res = res * x;
      x = x * x;
      t = t >> 1;
    }
    return res;
  }

  double myPow1(double x, int n) {
    ll t = n;
    if (t == 0) { return 1.0f; }
    if (t < 0) {
      x = 1 / x;
      t = labs(t);
    }
    return myPow(x * x, t / 2) * (t % 2 ? x : 1.0);
  }
};

void test(double x, int n) {
  Solution go;
  double ret = go.myPow(x, n);
  trace(x, n, ret);
}

int main() {
  test(2.0, 10);
  test(-2, 10);
  test(-2.1345, 9);
  test(2.3456, (1<<30)); 
  test(2, INT_MAX);
  test(1.3435, INT_MIN);
  return 0;
}
