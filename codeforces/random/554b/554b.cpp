//============================================================================
// Name        : 554b
// Date        : Mon Apr 15 21:39:19 CST 2019
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

int get(vs& a) {
  int n = sz(a);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    bool ok = 1;
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == '0') {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ++ret;
    }
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  vs a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ret = 0;
  for (int r = 0; r < n; ++r) {
    vs t = a;
    for (int c = 0; c < n; ++c) {
      if (t[r][c] == '0') {
        for (int h = 0; h < n; ++h) {
          t[h][c] = (t[h][c] == '0' ? '1' : '0');
        }
      }
    }
    amax(ret, get(t));
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

