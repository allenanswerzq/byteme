//============================================================================
// Name        : b
// Date        : Sat Apr  6 19:48:01 CST 2019
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

inline bool check(vi& a, int k, int h) {
  vi b(a.begin(), a.begin() + k);
  sort(rall(b));
  for (int i = 0; i < k; i += 2) {
    // int c = (i + 1 < k ? b[i + 1] : b[i]);
    // h -= max(b[i], c);
    h -= b[i];
    if (h < 0) {
      return 0;
    }
  }
  return 1;
}

void solve() {
  int n, h;
  cin >> n >> h;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  // [0....n-1]
  // int lo = -1, hi = n;
  int lo = 0, hi = n + 1;
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (check(a, mid, h)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  output(lo);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

