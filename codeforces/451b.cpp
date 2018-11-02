#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << endl
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(v) cout << (v) << endl
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


int main(int argc, char** argv) {
  int n; cin >> n >> ws;
  vi aa(n, 0);
  fori (i, 0, n) {
    cin >> aa[i];
  }
  vi bb = aa;
  sort(all(bb));

  // pvi(aa, 1);
  // pvi(bb, 1);

  int lo = -1;
  fori (i, 0, sz(aa)) {
    if (aa[i] != bb[i]) {
      lo = i;
      break;
    }
  }
  
  // Already sorted. 
  if (lo == -1) {
    outret("yes");
    cout << 1 << " " << 1 << endl;
    return 0;
  }

  int hi = -1;
  fori (i, 0, sz(aa)) {
    if (bb[i] == aa[lo]) {
      hi = i;
    }
    if (hi != -1) {
      while (++i < sz(aa)) {
        if (aa[i] != bb[i]) {
          outret("no");
          return 0;
        }
      }
    }
  }

  int r1 = lo, r2 = hi;
  int cnt = hi - lo; 
  while (lo <= r2 && hi >= 0) {
    // trace(lo, hi, aa[lo], bb[hi]);
    if (aa[lo] != bb[hi]) {
      outret("no");
      return 0;
    }
    ++lo; --hi;
  }

  outret("yes");
  cout << r1 + 1 << " " << r2 + 1 << endl;

  return 0;
}
