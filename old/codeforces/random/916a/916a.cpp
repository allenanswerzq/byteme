//============================================================================
// Name        : 916a
// Date        : Sun Apr 14 22:05:53 CST 2019
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
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n)
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

bool check(int a, int b) {
  if (a % 10 == 7 || b % 10 == 7) {
    return 1;
  }
  return 0;
}

void solve() {
  int n;
  cin >> n;
  int h, m;
  cin >> h >> m;
  int ret = 0;
  while (1) {
    if (check(h, m)) {
      output(ret);
      return;
    }
    m -= n;
    if (m < 0) {
      m += 60;
      h--;
    }
    if (h < 0) {
      h += 24;
    }
    ++ret;
  }
}

void solve2() {
  int n;
  cin >> n;
  int h, m;
  cin >> h >> m;
  int t0 = h * 60 + m;
  int ret = (int)1e9 + 7;
  for (int i = 0; i < 24; ++i) {
    for (int j = 0; j < 60; ++j) {
      int t1 = i * 60 + j;
      if (check(i, j)) {
        int d = t1 <= t0 ? t0 - t1
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0); : 24 * 60 - t1 + t0;
        if (d % n == 0) {
          amin(ret, d / n);
        }
      }
    }
  cin.tie(0);
  solve2();
  return 0;
}

