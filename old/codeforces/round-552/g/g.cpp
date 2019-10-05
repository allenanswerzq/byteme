//============================================================================
// Name        : g
// Date        : Wed Apr 17 22:06:48 CST 2019
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
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) pvar(x); fori(i, s, n) prt(x, i, n)
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

const int maxm = (int) 1e7 + 7;
vi dp[maxm];
void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (sz(dp[a[i]]) < 2) {
      dp[a[i]].pb(i);
    }
  }
  trace(a);
  pair<ll, pii> ret = {(ll)1e18 + 7, {-1, -1}};
  for (int i = 1; i < maxm; ++i) {
  // Try every number to see if this number can be the greatest
  // common divisor for same pair(a, b).
    vi e;
    for (int j = i; j < maxm && sz(e) < 2; j += i) {
      if (sz(dp[j])) {
        e.pb(dp[j][0]);
      }
      if (sz(dp[j]) == 2 && sz(e) < 2) {
        e.pb(dp[j][1]);
      }
    }
    if (sz(e) == 2) {
    // Found a desirable pair, compute lcm.
      pair<ll, pii> tmp = {(ll)a[e[0]] / i * (ll)a[e[1]], {e[0], e[1]}};
      trace(i, e, tmp, ret);
      amin(ret, tmp);
    }
  }
  if (ret.y.x > ret.y.y) {
    swap(ret.y.x, ret.y.y);
  }
  cout << ret.y.x + 1 << " " << ret.y.y + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
