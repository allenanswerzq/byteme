//============================================================================
// Name        : 337a
// Date        : Tue Apr  9 09:55:17 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << "\n"; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve() {
  int h, w, k;
  cin >> h >> w >> k;
  vs a(h);
  for (int i = 0; i < h; ++i) {
    cin >> a[i];
  }
  int s = 0;
  pii e;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '.') {
        ++s;
        e.x = i, e.y = j;
      }
    }
  }
  trace(s, k);
  int cnt = 0;
  vector<vector<bool>> vis(h, vector<bool>(w));
  function<bool(int, int)> dfs = [&](int i, int j) {
    assert(a[i][j] == '.');
    a[i][j] = 'X';
    vis[i][j] = 1;
    if (++cnt == s - k) {
      return true;
    }
    vvi dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for (auto d : dirs) {
      int x = i + d[0];
      int y = j+ d[1];
      if (0 <= x && x < h && 0 <= y && y < w) {
        if (a[x][y] == '.' && !vis[x][y]) {
          if (dfs(x, y)) {
            return true;
          }
        }
      }
    }
    return false;
  };
  dfs(e.x, e.y);
  vs b = a;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == 'X') {
        b[i][j] = '.';
      } else if (a[i][j] == '.') {
        b[i][j] = 'X';
      }
    }
  }
  // par(a, 0, h, 0);
  par(b, 0, h, 0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

