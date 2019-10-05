//============================================================================
// Name        : 779c
// Date        : Wed Apr 10 10:50:09 CST 2019
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
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vi b(n);
  for (int j = 0; j < n; ++j) {
    cin >> b[j];
  }
  vpii d(n);
  for (int i = 0; i < n; ++i) {
    d[i] = {b[i] - a[i], i};
  }
  sort(rall(d));
  d.pb({0, -1});
  for (int i = 0; i <= n; ++i) {
    if (d[i].x <= 0) {
    // If the price goes higher after a week,
    // We should buy right now.
      k = max(k, i);
      break;
    }
  }
  trace(d, k);
  ll ret = 0;
  for (int i = 0; i < n; ++i) {
    if (i < k) {
      ret += a[d[i].y];
    } else {
      ret += b[d[i].y];
    }
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); solve();
  return 0;
}

