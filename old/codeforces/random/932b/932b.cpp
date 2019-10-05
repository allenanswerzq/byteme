//============================================================================
// Name        : 932b
// Date        : Fri Apr 12 16:15:45 CST 2019
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

int f(int n) {
  int ret = 1;
  while (n) {
    int d = n % 10;
    ret *= d ? d : 1;
    n /= 10;
  }
  return ret;
}

int g(int n) {
  if (n < 10) {
    return n;
  } else {
    return g(f(n));
  }
}

void solve() {
  map<int, vi> mp;
  for (int i = 1; i <= (int) 1e6 + 7; ++i) {
    mp[g(i)].pb(i);
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    auto lo = lower_bound(all(mp[k]), l);
    auto hi = upper_bound(all(mp[k]), r);
    output(hi - lo);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

