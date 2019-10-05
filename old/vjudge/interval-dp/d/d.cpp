//============================================================================
// Name        : d
// Date        : Sat Apr  6 10:58:12 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <cstring>
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
vi a;
int dp[120][120];
int rec(int lo, int hi) {
  int& ret = dp[lo][hi];
  // trace(lo, hi, ret);
  if (ret != inf) {
    return ret;
  }
  if (lo + 1 == hi) {
    return ret = 0;
  }
  for (int i = lo + 1; i < hi; ++i) {
    amin(ret, rec(lo, i) + rec(i, hi) + a[lo] * a[i] * a[hi]);
  }
  return ret;
}

void solve() {
  int n; cin >> n;
  a = vi(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  mst(dp, 0x3f);
  output(rec(0, n - 1));
}

void solve2() {
  int n; cin >> n;
  a = vi(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vvi dp(n, vi(n, inf));
  for (int L = n - 1; L >= 0; --L) {
    for (int R = L; R < n; ++R) {
      if (L == R || L + 1 == R) {
        dp[L][R] = 0;
      }
      for (int k = L + 1; k <= R - 1; ++k) {
        amin(dp[L][R], dp[L][k] + a[L] * a[k] * a[R] + dp[k][R]);
      }
    }
  }
  trace(a, dp);
  output(dp[0][n - 1]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve2();
  return 0;
}
