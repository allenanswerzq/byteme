#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
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

const int maxn = 110;
int aa[maxn][maxn];
void solve() {
  int n, m;
  cin >> n >> m;
  vi sr(n), sc(m);
  fori (i, 0, n) cin >> sr[i];
  fori (i, 0, m) cin >> sc[i];

  // pvi(sr, 1);
  // pvi(sc, 1);

  fori (i, 0, n) {
    fori (j, 0, m) {
      int x = min(sr[i], sc[j]);
      aa[i][j] = x;
      sr[i] -= x; sc[j] -= x;
    }
  }

  // pvi(sr, 1);
  // pvi(sc, 1);

  fori (i, 0, n) {
    par(aa[i], m, 0);
  }
}

int main() {
  solve();
  return 0;
}

