//============================================================================
// Name        : 558a
// Date        : Wed Apr 10 19:13:19 CST 2019
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
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
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
  int n;
  cin >> n;
  vpii a, b;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x > 0) {
      a.pb({x, y});
    } else {
      b.pb({x, y});
    }
  }
  sort(all(a));
  sort(rall(b));
  trace(a, b);
  if (sz(a) < sz(b)) {
    swap(a, b);
  }
  int ret = 0;
  if (sz(a) == sz(b)) {
    for (int i = 0; i < sz(a); ++i) {
      ret += a[i].y + b[i].y;
    }
  } else {
    for (int i = 0; i < min(sz(a), sz(b) + 1); ++i) {
      ret += a[i].y;
    }
    for (int i = 0; i < sz(b); ++i) {
      ret += b[i].y;
    }
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

