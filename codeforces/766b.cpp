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
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


int main(int argc, char** argv) {
  int n; cin >> n;
  vi aa(n, 0);
  fori (i, 0, n) {
    cin >> aa[i];
  }

  sort(all(aa));
  pvi(aa, 1);
  
  bool ok = 0; 
  fori (i, 2, sz(aa)) {
    int a = aa[i], b = aa[i - 1], c = aa[i - 2];
    // c <= b <= a
    if (c + b > a && a - c < b) {
      trace(c, b, a);
      ok = 1;
      break;
    }
  }  

  outret(ok ? "YES" : "NO");

  // fori (i, 0, sz(aa) - 2) {
  //   if (i > 0 && aa[i] == aa[i - 1]) continue;
  //   int lo = i + 1, hi = sz(aa) - 1;
  //   while (lo < hi) {
  //     int a = aa[i], b = aa[lo], c = aa[hi];
  //     if (a + b > c && c - a < b) {
  //       // trace(a, b, c);
  //       outret("YES"); return 0;
  //     } else if (a + b <= c) {
  //       ++lo; 
  //     } else if (c - a >= b) {
  //       --hi;
  //     }
  //   } 

  //   lo = i + 1, hi = sz(aa) - 1;
  //   while (lo < hi) {
  //     int a = aa[i], b = aa[lo], c = aa[hi];
  //     if (a + b > c && c - a < b) {
  //       // trace(a, b, c);
  //       outret("YES"); return 0;
  //     } else if (a + b <= c) {
  //       --hi; 
  //     } else if (c - a >= b) {
  //       ++lo;
  //     }
  //   } 

  // }

  // outret("NO");


  return 0;
}

