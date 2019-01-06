#include <bits/stdc++.h>
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
  bool isPalindrome(int x) {
    if(x < 0 || (x!=0 && x%10 == 0)) return false;
    ll sum = 0;
    while(x > sum) {
      sum = sum * 10 + x % 10;
      x = x / 10;
    }
    return (x == sum) || (x == sum/10);
  }

  bool isPalindrome1(int x) {
    if (x < 0 ) return false;
    ll tmp = 0;
    int y = x;
    do  {
      tmp = tmp * 10 + y%10;
      y /= 10;
    } while (y);

    return tmp == x;
  }
};

void test(int x) {
  Solution go;
  int r = go.isPalindrome(x);
  output(1, r);
}

int main() {
  test(0);
  test(1221);
  test(-1221);
  test(1111111122); // overflow
  return 0;
}
