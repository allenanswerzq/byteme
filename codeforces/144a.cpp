#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define output(val) cout << (val) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (val) << endl

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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main(int argc, char** argv) {
  int n; cin >> n >> ws;
  int mx = 0, mi = 200;
  int ix = 0, ii = 0;
  fori (i, 1, n + 1) {
    int a; cin >> a;
    if (a > mx) { mx = a; ix = i; }
    if (a <= mi) { mi = a; ii = i; }
  }

  // trace(mx, mi, ix, ii);
  int ret = 0;
  if (ix < ii) {
    ret = (ix - 1) + (n - ii);
  } else if (ix > ii) {
    int nx = (ix + ii) / 2;
    int ni = nx + 1;
    // trace(nx, ni);
    ret = (ix - nx) + (ni - ii) + (nx - 1) + (n - ni) - 1;
  } 
  output(ret); 

  return 0;
}
