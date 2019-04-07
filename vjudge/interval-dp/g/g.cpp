//============================================================================
// Name        : g
// Date        : Sun Apr  7 16:06:38 CST 2019
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

const int inf = 0x3f3f3f3f;
vvi dp;
string a, b;

int rec(int lo, int hi) {
  int& ret = dp[lo][hi];
  // trace(ret, lo, hi);
  if (ret != inf) {
    return ret;
  }
  if (lo > hi) {
    return ret = 0;
  }
  ret = rec(lo + 1, hi) + 1;
  for (int i = lo + 1; i <= hi; ++i) {
    if (b[lo] == b[i]) {
      amin(ret, rec(lo + 1, i) + rec(i + 1, hi));
    }
  }
  return ret;
}

void solve() {
  int n = sz(a);
  dp = vvi(n + 1, vi(n + 1, inf));
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      rec(i, j);
    }
  }
  vi ret(n);
  for (int i = 0; i < n; ++i) {
    ret[i] = dp[0][i];
    if (a[i] == b[i]) {
      if (i == 0) {
        ret[i] = 0;
      } else {
        ret[i] = ret[i - 1];
      }
    }
    for (int j = 0; j < i; ++j) {
      amin(ret[i], ret[j] + dp[j + 1][i]);
    }
  }
  // trace(dp[0], ret);
  output(ret[n - 1]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> a >> b) {
    solve();
  }
  return 0;
}

