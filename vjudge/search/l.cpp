// #include <bits/stdc++.h>
#include <utility>
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

const int maxn = 200;
int n, m;
char aa[maxn][maxn];
int visit[maxn][maxn];
int dx[] = {0, 0, -1, 1, -1, 1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool go(int i, int j) {
  if (visit[i][j]) return 0;

  deque<pii> dq;
  dq.pb({i, j});
  visit[i][j] = 1;
  while (sz(dq)) {
    int l = sz(dq);
    fori (j, 0, l) {
      pii cur = dq.front(); dq.pop_front();
      int x = cur.fi, y = cur.se;  
      fori (k, 0, 8) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
        if (visit[nx][ny] || aa[nx][ny] == '*') continue;
        visit[nx][ny] = 1;
        dq.pb({nx, ny});
      }
    } 
  }
  return 1;
}

void solve() {

  fori (i, 0, n) fori (j, 0, m) 
    cin >> aa[i][j];

  // fori (i, 0, n) {
  //   par(aa[i], m, 1);
  // }

  int ret = 0;
  mst(visit, 0);
  fori (i, 0, n) fori (j, 0, m) {
    if (aa[i][j] == '@') {
      if (go(i, j)) ++ret;
    }
  }

  output(ret);
}

int main() {
  while (cin >> n >> m) {
    if (!n && !m) break;
    solve();
  }
  return 0;
}

