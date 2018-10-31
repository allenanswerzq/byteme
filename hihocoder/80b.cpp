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

const int maxn = 1e5 + 7;
const int mod = 1e9 + 7;

int add(int a, int b) {
  int c = a + b;
  if (c >= mod) c -= mod;
  if (c < 0) c += mod;
  return c;
}

int dp[maxn][10];
vvi g = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
vvi dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pii pos[10];
void solve() {
  int n; cin >> n;
  fori (i, 0, 4) 
    fori (j, 0, 3) 
      if (g[i][j] != -1)
        pos[g[i][j]] = {i, j};

  mst(dp, 0);
  fori (i, 0, 10) dp[0][i] = 1;

  // trace(n);

  // fori (i, 0, n) {
  //   par(dp[i], 10, 1);
  // }

  // fori (i, 0, 10) {
  //   trace(pos[i].first, pos[i].second);
  // }

  fori (i, 1, n) fori (j, 0, 10) {
    auto e = pos[j];
    fora (d, dirs) {
      int x = e.first + d[0], y = e.second + d[1];
      if (0 <= x && x < 4 && 0 <= y && y < 3 && g[x][y] != -1) {
        // trace(e.first, e.second, x, y);
        dp[i][g[x][y]] = add(dp[i][g[x][y]], dp[i-1][j]);
      }
    }
  }  

  // fori (i, 0, n) {
  //   par(dp[i], 10, 1);
  // }

  int ret = 0;
  fori (i, 0, 10) ret = add(ret, dp[n-1][i]);
  output(ret);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  solve();
  return 0;
}

