#include <vector>
#include <cstring>
#include <iostream>
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

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//   cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//   const char* split = strchr(names + 1, ',');
//   cout.write(names, split - names) << ": " << arg << " |";
//   _f(split, args...);
// }

// double tick() {
//   static clock_t old;
//   clock_t now = clock();
//   double diff = 1.0 * (now - old);
//   diff /= CLOCKS_PER_SEC;
//   old = now;
//   return diff;
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int inf = (1 << 30);
const int maxn = 17;
int aa[maxn][maxn], bb[maxn][maxn], cc[maxn][maxn];
int n, m, ret, cnt;
int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

void flip(int i, int j) {
  ++cnt;
  bb[i][j] = 1;
  cc[i][j] ^= 1;
  fori (k, 0, 4) {
    int ni = i + x[k], nj = j + y[k];
    if (-1 < ni && ni < n && -1 < nj && nj < m)
      cc[ni][nj] ^= 1;
  }
}

bool ok(int k) {
  cnt = 0;
  mst(bb, 0);
  memcpy(cc, aa, sizeof(aa));
  fori (j, 0, m)
    if (k & (1 << (m - 1 - j))) flip(0, j);

  fori (i, 1, n)
    fori (j, 0, m)
      if (cc[i - 1][j]) flip(i, j);

  fori (j, 0, m)
    if (cc[n - 1][j]) return 0;
  return 1;
}

int main() {
  cin >> n >> m;
  fori (i, 0, n)
    fori (j, 0, m)
      cin >> aa[i][j];

  // fori (i, 0, n) {
  //   par(aa[i], m, 1);
  // }

  ret = inf;
  int ix = -1;
  fori (i, 0, (1 << m))
    if (ok(i) && cnt < ret)
      ret = cnt, ix = i;

  // trace(ret, ix);
  if (ix >= 0) {
    ok(ix);
    fori (i, 0, n) {
      par(bb[i], m, 0);
    }
  } else {
    output("IMPOSSIBLE");
  }
  return 0;
}
