// #include <bits/stdc++.h>
#include <vector>
#include <deque>
#include <iostream>
#include <cstring>
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

const int maxn = 220;
const int inf = (1 << 20);
char aa[maxn][maxn];
int dist[maxn][maxn];
int dist2[maxn][maxn];
int visit[maxn][maxn];
int n, m, yy, mm;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool check(int x, int y) {
  if (!(0 <= x && x < n && 0 <= y && y < m)) return 0;
  if (visit[x][y] || aa[x][y] == '#') return 0;
  visit[x][y] = 1;
  return 1;
}

void bfs(int ss, int dd[maxn][maxn]) {
  mst(visit, 0);
  deque<int> dq;
  dq.clear();
  dq.pb(ss);
  visit[ss / n][ss % n] = 1;

  int level = 0;
  while (sz(dq)) {
    ++level;
    int l = sz(dq);
    fori (i, 0, l) {
      int cur = dq.front(); dq.pop_front();
      int x = cur / n, y = cur % n;
      // trace(cur, x, y);
      fori (i, 0, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!check(nx, ny)) continue;
        if (aa[nx][ny] == '@') dd[nx][ny] = level;
        dq.pb(nx * n + ny);
        // trace(nx, ny);
      }
    }
  }
}

void solve() {
  fori (i, 0, n) fori (j, 0, m) {
    cin >> aa[i][j];
    if (aa[i][j] == 'Y') yy = i * n + j;
    if (aa[i][j] == 'M') mm = i * n + j;
  }

  // fori (i, 0, n) {
  //   par(aa[i], m, 1);
  // }

  mst(dist, 0);
  mst(dist2, 0);
  bfs(yy, dist);
  bfs(mm, dist2);

  // fori (i, 0, n) {
  //   par(dist[i], m, 1);
  // }

  // fori (i, 0, n) {
  //   par(dist2[i], m, 1);
  // }

  int ret = inf;
  fori (i, 0, n) fori (j, 0, m) {
    if (aa[i][j] == '@' && dist[i][j] && dist2[i][j])
      ret = min(ret, dist[i][j] + dist2[i][j]);
  }

  output(ret * 11);

}

int main() {
  while (cin >> n >> m) {
    solve();
  }
  return 0;
}

