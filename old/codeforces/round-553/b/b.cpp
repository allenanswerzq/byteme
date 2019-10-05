//============================================================================
// Name        : b
// Date        : Fri Apr 19 09:33:27 CST 2019
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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve() {
  int h, w;
  cin >> h >> w;
  vvi a(h, vi(w));
  vvi b(h);
  int gt = -1;
  int cur = 0;
  vi ret(h);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
      if (sz(b[i]) == 0 || a[i][j] != a[i][b[i].back()]) {
        b[i].pb(j);
      }
    }
    cur ^= a[i][0];
    ret[i] = 0;
    if (sz(b[i]) > 1) {
      gt = i;
    }
  }
  trace(b);
  if (cur == 0) {
    if (gt == -1) {
      output("NIE");
      return;
    } else {
      cur = cur ^ a[gt][b[gt][0]] ^ a[gt][b[gt][1]];
      ret[gt] = b[gt][1];
    }
  }
  output("TAK");
  for (int i = 0; i < h; ++i) {
    ret[i]++;
  }
  par(ret, 0, h, 0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
