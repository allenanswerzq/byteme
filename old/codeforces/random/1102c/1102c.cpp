//============================================================================
// Name        : 1102c
// Date        : Sun Apr 14 21:30:48 CST 2019
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

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a));
  for (int i = 0; i < n; i += 2) {
    a[i] = max(0, a[i] - x);
    if (i + 1 < n) {
      a[i + 1] = a[i + 1] + y;
    }
  }
  trace(a);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += a[i] == 0;
  }
  if (x > y) {
    ret = n;
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
