//============================================================================
// Name        : 875a
// Date        : Thu Apr 11 09:31:34 CST 2019
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
#define jam(x, n) cout << "Case #" << x << ": " << n << " "
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
  int n;
  cin >> n;
  vi ret;
  for (int i = 0; i <= 100; ++i) {
    int x = n - i;
    vi b;
    while (x) {
      b.pb(x % 10);
      x /= 10;
    }
    int s = accumulate(all(b), 0);
    if (s == i) {
      ret.pb(n - i);
    }
  }
  sort(all(ret));
  output(sz(ret));
  if (sz(ret)) {
    par(ret, 0, sz(ret), 0);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

