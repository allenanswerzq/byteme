//============================================================================
// Name        : 999c
// Date        : Sun Apr 14 21:09:18 CST 2019
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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vi tot(26);
  for (int i = 0; i < n; ++i) {
    tot[s[i] - 'a']++;
  }
  vi rst = tot;
  for (int i = 0; i < 26 && k > 0; ++i) {
    if (k >= rst[i]) {
      k -= rst[i];
      rst[i] = 0;
    } else {
      rst[i] -= k;
      k = 0;
    }
  }
  trace(rst, tot);
  string ret;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    // trace(i, c, rst[c], tot[c]);
    if (rst[c] < tot[c]) {
      rst[c]++;
    } else if (rst[c] == tot[c]) {
      ret += s[i];
    } else {
      assert(0);
    }
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

