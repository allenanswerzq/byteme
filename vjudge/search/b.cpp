// #include <bits/stdc++.h>
#include <set>
#include <deque>
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

int L, R, C;
int src, dst, ret;
char aa[40][40][40];
int visit[1 << 16];
int xx[6] = {0, 0, 0, 0, 1, -1};
int yy[6] = {0, 1, -1, 0, 0, 0};
int zz[6] = {1, 0, 0, -1, 0, 0};

int bfs() {

  int level = 0;
  deque<int> dq;
  dq.pb(dst);
  visit[dst] = 1;

  while (sz(dq)) {
    int n = sz(dq);
    fori (i, 0, n) {
      int cur = dq.front(); dq.pop_front();
      if (cur == src) return level;
      int l = (cur >> 10) & 0x1f, r = (cur >> 5) & 0x1f, c = (cur) & 0x1f;
      // trace(l, r, c, level);
      fori (i, 0, 6) {
        int nl = l + xx[i], nr = r + yy[i], nc = c + zz[i];
        int nxt = (nl << 10) | (nr << 5) | nc;
        if (0 <= nl && nl < L && 0 <= nr && nr < R &&
            0 <= nc && nc < C && aa[nl][nr][nc] != '#') {
          if (visit[nxt]) continue;
          visit[nxt] = 1;
          dq.pb(nxt);
        }
      }
    }
    ++level;
  }
  // Not reach to source.
  return -1;
}

void solve() {
  mst(aa, 0);
  mst(visit, 0);

  fori (l, 0, L) fori (r, 0, R) fori (c, 0, C) {
    char a; cin >> a;
    aa[l][r][c] = a;
    if (a == 'E') { dst = (l << 10) | (r << 5) | c; }
    if (a == 'S') { src = (l << 10) | (r << 5) | c; }
  }

  ret = bfs();
  if (ret != -1) {
    cout << "Escaped in " << ret << " minute(s)." << '\n';
  } else {
    cout << "Trapped!" << '\n';
  }
}

int main() {
  while (cin >> L >> R >> C) {
    if (!L && !R && !C) break;
    solve();
  }
  return 0;
}

