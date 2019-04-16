//============================================================================
// Name        : 946b
// Date        : Mon Apr 15 17:53:56 CST 2019
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

void rec(ll& a, ll& b) {
  if (!a || !b) {
    return;
  }
  if (a >= 2 * b) {
    a = a % (2 * b) == 0 ? 0 : a % (2 * b);
  }
  if (!a) {
    return;
  }
  if (b >= 2 * a) {
    b = b % (2 * a);
    if (!b) {
      return;
    }
    rec(a, b);
  }
}

void solve() {
  ll a, b;
  cin >> a >> b;
  rec(a, b);
  cout << a << " " << b << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

