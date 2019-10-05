//============================================================================
// Name        : d
// Date        : Mon Apr  8 21:34:55 CST 2019
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
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vl a(x), b(y), c(z);
  for (int i = 0; i < x; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < y; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < z; ++i) {
    cin >> c[i];
  }
  sort(rall(a));
  sort(rall(b));
  sort(rall(c));
  // trace(a, b, c);
  vl ret;
  for (int i = 0; i < sz(a); ++i) {
    for (int j = 0; j < sz(b); ++j) {
      for (int h = 0; h < sz(c); ++h) {
        if ((i + 1) * (j + 1) * (h + 1) <= k) {
          ret.pb(a[i] + b[j] + c[h]);
        } else {
          break;
        }
      }
    }
  }
  sort(rall(ret));
  // par(ret, 0, k, 0);
  for (int i = 0; i < k; ++i) {
    cout << ret[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

