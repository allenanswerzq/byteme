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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 20;
int n, m, k;
ll dp[1 << maxn][maxn];
int aa[maxn];
int bb[maxn][maxn];

int len(int mask) {
  int r = 0;
  fori (i, 0, 32) {
    r += mask & (1 << i) ? 1 : 0;
  }
  return r;
}

int main() {
  cin >> n >> m >> k;
  fori (i, 0, n) cin >> aa[i];
  fori (i, 0, k) {
    int x, y, z;  cin >> x >> y >> z;
    bb[x - 1][y - 1] = z;
  }

  fori (i, 0, n) {
    dp[1 << i][i] = aa[i];
  }

  // par(aa, n, 1);
  // fori (i, 0, (1 << n)) {
  //   par(dp[i], n, 1);
  // } 

  fori (mask, 0, (1 << n)) {
    fori (j, 0, n) {
      if (!(mask & (1 << j))) continue;
      fori (k, 0, n) {
        if ((mask & (1 << k))) continue;
        ll nmask = mask | (1 << k);
        // trace(mask, j, k, nmask, dp[mask][j], aa[k], bb[j][k]);
        dp[nmask][k] = max(dp[nmask][k], dp[mask][j] + aa[k] + bb[j][k]);
      }
    } 
  }

  // fori (i, 0, (1 << n)) {
  //   par(dp[i], n, 1);
  // } 

  ll ret = 0;
  // trace(m);
  fori (mask, 0, (1 << n)) {
    if (len(mask) == m) {
      fori (i, 0, n) {
        // trace(mask, dp[mask][i]);
        ret = max(ret, dp[mask][i]); 
      }
    }
  }

  output(ret);
  return 0;
}

