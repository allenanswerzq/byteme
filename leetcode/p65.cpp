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

// TODO
class Solution {
public:
  bool isNumber(string ss) {
    bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
    int n = ss.size();
    for (int i = 0; i < n; ++i) {
      if (ss[i] == ' ') {
        if (i < n - 1 && ss[i + 1] != ' ' && (num || dot || exp || sign)) 
          return false;
      } else if (ss[i] == '+' || ss[i] == '-') {
        if (i > 0 && ss[i - 1] != 'e' && ss[i - 1] != ' ') return false;
        sign = true;
      } else if (ss[i] >= '0' && ss[i] <= '9') {
        num = true;
        numAfterE = true;
      } else if (ss[i] == '.') {
        if (dot || exp) return false;
        dot = true;
      } else if (ss[i] == 'e') {
        if (exp || !num) return false;
        exp = true;
        numAfterE = false;
      } else return false;
    }
    return num && numAfterE;
  }
};

void test(string aa) {
  Solution go;
  int r = go.isNumber(aa);
  output(1, r);
}

int main() {
  test("  343   ");
  test("0");
  test(" ");
  test(".1");
  test("e2");
  return 0;
}
