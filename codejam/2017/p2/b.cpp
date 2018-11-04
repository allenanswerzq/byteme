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

const int maxn = 3002;
char g[maxn][maxn];
ll dp[maxn][maxn];

ll solve() {
  int r, c, k; 
  cin >> r >> c >> k;
  mst(g, 0);
  mst(dp, 0);

  fori (i, 0, k) {
    int x, y; cin >> x >> y;
    g[x][y] = 1;
  }

  fori (i, 0, r) {
    fori (j, 0, c) {
      if (g[i][j] == 1) continue;
      if (i == 0) dp[0][j] = 1;
      else if (j == 0) dp[i][0] = 1;
      else {
        ll len = (1 << 29);
        if (i >= 1) len = min(dp[i - 1][j], len);
        if (j >= 1) len = min(dp[i][j - 1], len);
        if (i >= 1 && j >= 1) len = min(dp[i-1][j-1], len);
        dp[i][j] = len + 1;
      }
    }
  }

  // fori (i, 0, r) { 
  //   par(dp[i], c, 1);
  // }

  ll res = 0;
  fori (i, 0, r) {
    fori (j, 0, c) {
      res += dp[i][j];
    }
  }
  return res;
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    ll r = solve();
    codejam(i, r); 
  }  

  return 0;
}
