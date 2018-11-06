// #include <bits/stdc++.h>
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
#define codejam(ix, v) cout << "Case " << (ix) << ": " << (v) << '\n'
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

const int maxn = 20;
const int inf = (1 << 30);

int n, m; 
vi aa, bb;
char gg[maxn][maxn];
int visit[maxn * maxn];
vvi dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int bfs() {

  mst(visit, 0);
  deque<int> dq;
  dq.clear();

  int cnt = 0;
  fori (i, 0, sz(bb)) {
    if (visit[bb[i]]) continue;
    visit[bb[i]] = 1;
    dq.pb(bb[i]);
    // trace(bb[i] / n, bb[i] % n);
    ++cnt;
  }

  bb.clear();

  int level = 0;

  while (sz(dq)) {
    ++level;
    int l = sz(dq);
    fori (i, 0, l) {
      int cur = dq.front(); dq.pop_front();
      int x = cur / n, y = cur % n;
      // trace(cur, x, y);

      fori (i, 0, 4) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        int st = nx * n + ny;
        if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
        if (!(!visit[st] && gg[nx][ny] == '#')) continue;
        ++cnt;
        visit[st] = 1;
        dq.pb(st);
      }
    }  
  }

  // trace(level, cnt, sz(aa));
  return cnt == sz(aa) ? level - 1 : inf;

}

void solve(int kk) {
  cin >> n >> m;

  mst(gg, 0);
  aa.clear();

  fori (i, 0, n) fori (j, 0, m) {
    cin >> gg[i][j];
    if (gg[i][j] == '#') aa.pb(i * n + j);
  }

  // fori (i, 0, n) {
  //   par(gg[i], m, 1);
  // }

  // pvi(aa, 1);

  int ret = inf;
  fori (i, 0, sz(aa)) {
    fori (j, 0, sz(aa)) {
      bb.pb(aa[i]); bb.pb(aa[j]);
      ret = min(ret, bfs()); 
    }
  }
  codejam(kk, ret == inf ? -1 : ret);
}

int main() {
  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    solve(i);
  }
  return 0;
}

