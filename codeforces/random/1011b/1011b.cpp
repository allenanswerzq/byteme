//============================================================================
// Name        : 1011b
// Date        : Thu Apr 11 22:26:48 CST 2019
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

bool check(vi& a, int k, int n) {
  for (int i = 0; i < sz(a); ++i) {
    // Total amount of the food needed it we last `k` days.
    int s = k * n;
    if (a[i] >= s) {
      return true;
    } else {
    // Serve as many as people possible.
      n -= a[i] / k;
    }
  }
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(m);
  const int maxn = 120;
  vi cnt(maxn);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int lo = 0, hi = maxn;
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (check(cnt, mid, n)) {
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

