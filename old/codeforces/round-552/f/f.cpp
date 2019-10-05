//============================================================================
// Name        : f
// Date        : Wed Apr 17 21:52:46 CST 2019
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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vi price(n);
  for (int i = 0; i < n; ++i) {
    cin >> price[i];
  }
  vpii offer(m);
  for (int i = 0; i < m; ++i) {
    cin >> offer[i].x >> offer[i].y;
  }
  sort(all(price));
  price.resize(k);
  n = sz(price);
  assert(n == k);
  vl pre(n + 1);
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i] + price[i];
  }
  vl dp(n + 1);
  for (int i = 0; i <= n; ++i) {
    dp[i] = pre[i];
  }
  for (int bc = 1; bc <= n; ++bc) {
    // Compute the best cost if i chose to buy total number of `bc` goods.
    for (auto t : offer) {
      if (t.x <= bc) {
      // If i can apply this offer. i need to buy exactly t.x goods and
      // t.y most cheapest of them are free.
        amin(dp[bc], dp[bc - t.x] + pre[bc] - pre[bc - t.x + t.y]);
      }
    }
  }
  output(dp[n]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
