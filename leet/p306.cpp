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

// #define LOCAL_FILE

#define ll long long

class Solution {
public:
  bool isAdditiveNumber(string inp) {
  int n = sz(inp);
  fori (i, 1, n) {
  fori (j, i + 1, n) {
  string aa = inp.substr(0, i);
  string bb = inp.substr(i, j - i); 
  if ((sz(aa)>1 && aa[0]=='0') || (sz(bb)>1 && bb[0]=='0')) 
    continue;
  ll d1 = stoll(aa);
  ll d2 = stoll(bb);     
  // trace(aa, bb, d1, d2);
  ll d3 = d1 + d2;
  string cc = aa + bb + to_string(d3);
  while (sz(cc) < sz(inp)) {
    d1 = d2;
    d2 = d3; 
    d3 = d1 + d2;
    cc = cc + to_string(d3);
  }
  if (cc == inp) return 1;
  }
  } 
  return false;
  } 
};

void test(string inp) {
  Solution go;
  int r = go.isAdditiveNumber(inp);
  cout << r << endl;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("p306-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 

  test("1023");
  test("112358");
  test("199100199");

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
