//============================================================================
// Name        : e
// Date        : Fri Apr 19 13:10:15 CST 2019
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
#define fore(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) pvar(x); fore(i, s, n) prt(x, i, n)
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }
template <typename T> void put(T t) { cout << t << "\n"; }
template <typename T, typename U, typename... Args>
void put(T t, U u, Args... args) { cout << t << " "; put(u, args...); }

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
  int n;
  cin >> n;
  vi a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  trace(a);
  ll ret = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i - 1] < a[i]) {
      // a[i - 1] + 1 <= l <= a[i]
      // a[i] <= r <= n
      ret += (ll)(a[i] - a[i - 1]) * (n - a[i] + 1);
    }
    if (a[i - 1] > a[i]) {
      // 1 <= l <= a[i];
      // a[i] <= r <= a[i - 1] - 1;
      ret += (ll)a[i] * (a[i - 1] - a[i]);
    }
  }
  put(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
