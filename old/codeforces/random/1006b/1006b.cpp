//============================================================================
// Name        : 1006b
// Date        : Sat Apr 13 21:43:32 CST 2019
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
  int n, k;
  cin >> n >> k;
  vpii a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(all(a), [](const pii& a, const pii& b){
    if (a.x == b.x) {
      return a.y < b.y;
    } else {
      return a.x > b.x;
    }
  });
  trace(a);
  vi b;
  int ret = 0;
  for (int i = 0; i < k; ++i) {
    ret += a[i].x;
    b.pb(a[i].y);
  }
  sort(all(b));
  trace(b);
  vi d;
  int pr = 0;
  for (int i = 0; i < sz(b); ++i) {
    if (i == sz(b) - 1) {
      d.pb(n - pr);
    } else {
      d.pb(b[i] + 1 - pr);
    }
    pr = b[i] + 1;
  }
  output(ret);
  par(d, 0, sz(d), 0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

