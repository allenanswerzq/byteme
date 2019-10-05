//============================================================================
// Name        : 251a
// Date        : Sat Apr 13 16:54:56 CST 2019
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
  int n, d;
  cin >> n >> d;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  // Pay attention to overflow issue...
  ll ret = 0;
  int pr = 0;
  for (int i = 0; i < n; ++i) {
    int cur = upper_bound(a.begin() + i, a.end(), a[i] + d) - a.begin();
    ll k = pr - i;
    ll m = cur - i;
    ret += m * (m - 1) * (m - 2) / 6;
    ret -= k * (k - 1) * (k - 2) / 6;
    pr = cur;
  }
  output(ret);
}

void solve2() {
  int n, d;
  cin >> n >> d;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ret = 0;
  for (int i = 0; i < n; ++i) {
    // Choose a[i] as the leftmost one for this segment.
    int ix = upper_bound(a.begin() + i, a.end(), a[i] + d) - a.begin();
    int k = (ix - i - 1);
    // There is k * (k - 1) / 2 pairs can form a triplets with a[i].
    ret += (ll)k * (k - 1) / 2;
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve2();
  return 0;
}

