#include<bits/stdc++.h>using namespace std;

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
  int reverse(int x) {
    long long ret = 0;
    while ( x != 0 ) {
      ret = ret * 10 + x % 10;
      x = x / 10;
      if (ret >= INT_MAX || ret <= INT_MIN) return 0;
    } 
    return ret; 
  }

  int reverse1(int x) {
    if (x == 0) return x;
    long long ret = 0;
    vector<int> v;
    do {
      v.push_back(x % 10);
      x = x / 10;
    } while ( x );

    for (int i=0; i<v.size(); ++i) {
      ret = ret*10 + v[i];
      if (ret >= INT_MAX || ret <= INT_MIN) return 0;
    }
    return ret; 
  }
};

void test(int x) {
  Solution go;
  int res = go.reverse(x);
  output(1, res);
}

int main() {
  test(123);
  test(-123);
  test(1534236469);
  test(-2147483648);
  return 0;
}
