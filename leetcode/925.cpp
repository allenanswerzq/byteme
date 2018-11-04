#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

double tick() {
  static clock_t old;
  clock_t now = clock();
  double diff = 1.0 * (now - old);
  diff /= CLOCKS_PER_SEC;
  old = now;
  return diff;
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class Solution {
public:
  bool isLongPressedName(string aa, string bb) {
    int i = 0, j = 0;
    while (i < sz(aa) && j < sz(bb)) {
      if (aa[i] != bb[j]) return 0;
      while (i < sz(aa) && j < sz(bb) && aa[i] == bb[j]) {
        ++i; ++j; 
      }
      while (j < sz(bb) && aa[i - 1] == bb[j]) ++j;
    }  
    return i == sz(aa);
  }
};

void test(string aa, string bb) {
  Solution go;
  int r = go.isLongPressedName(aa, bb);
  output(r);
}

int main() {
 
  test("alex", "aaleex");
  test("saeed", "ssaaedd"); 
  test("leelee", "lleeelee"); 
  test("laiden", "laiden");

  return 0;
}

