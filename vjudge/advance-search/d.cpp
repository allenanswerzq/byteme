// #include <bits/stdc++.h>
#include <algorithm>
#include <deque>
#include <vector>
#include <cstring>
#include <iostream>
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

const int maxn = 120;
const int maxt = 1003;
int m, n, k, d;
vi castles[maxn];
int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
bool visit[maxt][maxn][maxn];
bool dead[maxt][maxn][maxn];
bool casts[maxn][maxn];

bool check(int x, int y) {
  if (!(0 <= x && x <= m && 0 <= y && y <= n)) {
    return 0;
  } else if (casts[x][y]) {
    return 0;
  } else {
    return 1;
  }
}

void dead_point(vi castle) {
  int dir = castle[0];
  int T = castle[1];
  int v = castle[2];
  int x = castle[3];
  int y = castle[4];

  for (int j = 1; ; ++j) {
    int px = x + j * dirs[dir][0];
    int py = y + j * dirs[dir][1];
    if (check(px, py)) {
      if (j % v == 0) {
        for (int h = j / v; h <= d; h += T) {
          dead[h][px][py] = 1;
        }
      }
    } else {
      return;
    }
  }
}

void dead_points() {
  mst(dead, 0);
  fori (i, 0, k) {
    dead_point(castles[i]);
  }
}

void bfs() {
  deque<pii> dq;
  dq.pb({0, 0});
  visit[0][0][0] = 1;

  int level = 0;
  while (sz(dq) && level < d) {
    int l = sz(dq);
    fori (i, 0, l) {
      pii cur = dq.front(); dq.pop_front();
      int x = cur.fi, y = cur.se;
      if (x == m && y == n) {
        output(level);
        return;
      }

      fori (i, 0, 5) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if (0 <= nx && nx <= m && 0 <= ny && ny <= n &&
            !visit[level + 1][nx][ny] &&
            !dead[level + 1][nx][ny] &&
            !casts[nx][ny]) {
          visit[level + 1][nx][ny] = 1;
          dq.pb({nx, ny});
        }
      }
    }
    ++level;
  }

  output("Bad luck!");
}


int parse(char c) {
  int dir;
  if (c == 'N') {
    dir = 0;
  } else if (c == 'S') {
    dir = 1;
  } else if (c == 'W') {
    dir = 2;
  } else {
    dir = 3;
  }
  return dir;
}

int main() {
  while (cin >> m >> n >> k >> d) {
    mst(visit, 0);
    mst(dead, 0);
    mst(casts, 0);
    fori (i, 0, k) {
      castles[i].clear();
    }

    fori (i, 0, k) {
      char c; int t, v, x, y;
      cin >> c >> t >> v >> x >> y;
      castles[i].pb(parse(c));
      castles[i].pb(t);
      castles[i].pb(v);
      castles[i].pb(x);
      castles[i].pb(y);
      casts[x][y] = 1;
    }

    dead_points();

    // fori (j, 0, 6) {
    //   fori (i, 0, m + 1) {
    //     par(dead[j][i], n + 1, 1);
    //   }
    //   pend;
    // }

    bfs();
    // while (1);
  }
  return 0;
}

