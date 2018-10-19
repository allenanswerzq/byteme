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

void solve() {
  map<int, int> mp;
  int n, k; cin >> n >> k;
  fori (i, 0, n) {
    string x; cin >> x;
    // aa[i].s = x;
    mp[sz(x)]++;
  } 

  string corr; cin >> corr;
  int l = sz(corr);

  int aa, bb;
  aa = bb = 0;
  fora (it, mp) {
    if (it.first < l) aa += it.second;
    if (it.first <= l) bb += it.second;
  }

  --bb;

  int mi = aa + aa / k * 5 + 1;
  int mx = bb + bb / k * 5 + 1; 
  cout << mi << " " << mx << '\n';
}

void solve2() {
  int n, k; cin >> n >> k;
  vs aa(n);
  fori (i, 0, n) {
    cin >> aa[i];
  }

  string pass; cin >> pass;

  int cnt = 0;
  fori (i, 0, n) 
    if (sz(aa[i]) < sz(pass)) 
      ++cnt; 

  int mi = cnt + cnt / k * 5 + 1;

  cnt = 0;
  fori (i, 0, n) 
    if (sz(aa[i]) <= sz(pass))  
      ++cnt;

  --cnt; 
  int mx = cnt + cnt / k * 5 + 1;

  cout << mi << " " << mx << '\n';

}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  solve();

  return 0;
}

