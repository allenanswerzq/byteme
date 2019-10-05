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

string solve() {
  string ss;
  cin >> ss;
  if (sz(ss) & 1) return "AMBIGUOUS";

  int n = sz(ss);
  vi enc(n + 1, 0), dec(n + 1, 0);
  fori (i, 1, n + 1)
    enc[i] = ss[i - 1] - 'A'; 

  dec[2] = enc[1];
  dec[n - 1] = enc[n];
  for (int i = 4; i <= n; i += 2) {
    // enc[i] = (dec[i-1] + dec[i + 1]) % 26
    dec[i] = (enc[i - 1] - dec[i - 2] + 26) % 26;
  }

  for (int i = n - 3; i >= 1; --i) {
    dec[i] = (enc[i + 1] - dec[i + 2] + 26) % 26;
  }
  
  // pvi(enc);
  // pvi(dec);

  string res = "";
  fori (i, 1, n + 1)
    res += dec[i] + 'A';
  return res; 
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    string r = solve();
    codejam(i, r); 
  }

  return 0;
}
