//============================================================================
// Name        : 508a
// Date        : Fri Apr 19 19:55:43 CST 2019
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
#define fore(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) pvar(x); fore(i, s, n) prt(x, i, n)
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }
template <typename T> void put(T t) { cout << t << "\n"; }
template <typename T, typename U, typename... Args>
void put(T t, U u, Args... args) { cout << t << " "; put(u, args...); }

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

int h, w, k;
vector<vector<int>> g;
bool check(int x, int y) {
  bool ret = 0;
  for (auto dir : vpii{{-1, 1}, {1, -1}, {-1, -1}, {1, 1}}) {
    int cnt = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        int nx = x + dir.x * i;
        int ny = y + dir.y * j;
        if (0 <= nx && nx < h && 0 <= ny && ny < w && g[nx][ny] == 1) {
          cnt++;
        }
      }
    }
    if (cnt == 4) {
      ret = 1;
      break;
    }
  }
  return ret;
}

void solve() {
  cin >> h >> w >> k;
  vpii a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].x--, a[i].y--;
  }
  g = vvi(h, vi(w));
  int ret = 0;
  for (int i = 0; i < k; ++i) {
    g[a[i].x][a[i].y] = 1;
    if (check(a[i].x, a[i].y)) {
      ret = i + 1;
      break;
    }
  }
  put(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
