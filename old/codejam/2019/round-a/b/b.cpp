//============================================================================
// Name        : b
// Date        : Sat Apr 20 14:12:01 CST 2019
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
#define fore(i, a, b) for (int i = a; i < b; ++i)
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) cout << #x << ": "; fore(i, s, n) prt(x, i, n)
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }
template <typename T> void output(T t) { cout << t << "\n"; }
template <typename T, typename U, typename... Args>
void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

const int inf = (1 << 30);
int h, w;
vector<string> g;
vector<vi> dist;
void bfs() {
  dist = vector<vi>(h, vi(w, inf));
  deque<pii> dq;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (g[i][j] == '1') {
        dq.pb({i, j});
        dist[i][j] = 0;
      }
    }
  }
  while (sz(dq)) {
    int x, y;
    tie(x, y) = dq.front();
    dq.pop_front();
    vector<pii> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for (auto dir : dirs) {
      int nx = x + dir.x;
      int ny = y + dir.y;
      if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) {
        continue;
      }
      if (g[nx][ny] == '1') {
        continue;
      }
      if (dist[nx][ny] > dist[x][y] + 1) {
        dist[nx][ny] = dist[x][y] + 1;
        dq.pb({nx, ny});
      }
    }
  }
}

bool check(int x) {
// Check if `x` can be the minimum delivery time.
  // |a| + |b| = max(|a + b|, |a - b|)
  // dist((x1, x2), (y1, y2)) =
  // max(abs(x1 + y1 - (x2 + y2)), abs(x1 - y1 - (x2 - y2));
  int plus_max = inf;
  int plus_min = -inf;
  int minus_max = inf;
  int minus_min = -inf;
  bool ok = 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (dist[i][j] > x) {
        plus_max = min(plus_max, i + j + x);
        plus_min = max(plus_min, i + j - x);
        minus_max = min(minus_max, i - j + x);
        minus_min = max(minus_min, i - j - x);
        ok = 0;
      }
    }
  }
  if (ok) {
    return 1;
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int plus = i + j, minus = i - j;
      if (plus_min <= plus && plus <= plus_max &&
          minus_min <= minus && minus <= minus_max) {
        return 1;
      }
    }
  }
  return 0;
}

void solve(int tc) {
  cin >> h >> w;
  g = vector<string>(h);
  for (int i = 0; i < h; ++i) {
    cin >> g[i];
  }
  bfs();
  // trace(h, w, g, dist);
  int lo = -1, hi = inf;
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    // trace(lo, hi, mid);
    // if (can(mid)) {
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << "Case #" << tc << ": " << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}

