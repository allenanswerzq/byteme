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

// ll solve_small() {
//   string a; cin >> a;
//   int n = sz(a);

//   ll lo, hi; cin >> lo >> hi;
//   ll res = 0;
//   fori (i, lo, hi + 1) {
//     if (a[(i - 1) % n] == 'B')
//       ++res; 
//   }
//   return res;
// }

const int maxn = 120;
ll aa[maxn];
ll bb[maxn]; 
ll solve() {
  string s; cin >> s;
  ll n = sz(s);
  ll lo, hi; cin >> lo >> hi;

  aa[0] = s[0] == 'B' ? 1 : 0;
  fori (i, 1, n) {
    if (s[i] == 'B') aa[i] = aa[i - 1] + 1;
    else aa[i] = aa[i - 1];
  }

  bb[n - 1] = s[n - 1] == 'B' ? 1 : 0;
  ford (i, n - 2, -1 ) {
    if (s[i] == 'B') bb[i] = bb[i + 1] + 1;
    else bb[i] = bb[i + 1];
  }

  // trace(s, lo, hi);
  // par(aa, n, 1);
  // par(bb, n, 1);

  // |0123456789|
  // |....ix--->|
  // |<---------|
  // |------>x..| 

  ll l = hi - lo + 1;
  ll ix = (lo - 1) % n;
  ll t = (l - (n - ix)) / n;
  ll x = (l - (n - ix) - 1) % n;
  ll r = (bb[ix] + (t * aa[n - 1]) + (x == n - 1 ? 0 : aa[x]));

  // trace(l, ix, t, x);
  return r;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 1, t + 1) {
    ll r = solve();
    codejam(i, r);  
  }  

  return 0;
}
