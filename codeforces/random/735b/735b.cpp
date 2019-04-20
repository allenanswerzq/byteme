//============================================================================
// Name        : 735b
// Date        : Fri Apr 19 22:05:06 CST 2019
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
#define fore(i, a, b) for (int i = a; i < b; ++i)
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) cout << #x << ": "; fore(i, s, n) prt(x, i, n)
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }
template <typename T> void output(T t) { cout << t << "\n"; }
template <typename T, typename U, typename... Args>
void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

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
  int n, a, b;
  cin >> n >> a >> b;
  vi g(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  sort(rall(g));
  trace(g);
  if (a > b) {
    swap(a, b);
  }
  vi e, f;
  for (int i = 0; i < a + b; ++i) {
    if (sz(e) < a) {
      e.pb(g[i]);
    } else if (sz(f) < b) {
      f.pb(g[i]);
    }
  }
  trace(e, f);
  double ret = accumulate(all(e), 0.0) / a;
  ret += accumulate(all(f), 0.0) / b;
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(8) << fixed;
  solve();
  return 0;
}
