//============================================================================
// Name        : 433b
// Date        : Tue Apr  9 15:35:48 CST 2019
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
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vl pe1(n + 1);
  for (int i = 0; i < n; ++i) {
    pe1[i + 1] = pe1[i] + a[i];
  }
  sort(all(a));
  vl pe2(n + 1);
  for (int i = 0; i < n; ++i) {
    pe2[i + 1] = pe2[i] + a[i];
  }
  auto get = [&](int t, int x, int y) {
    if (t == 1) {
      return pe1[y] - pe1[x - 1];
    } else {
      return pe2[y] - pe2[x - 1];
    }
  };
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, t;
    cin >> t >> x >> y;
    ll ret = get(t, x, y);
    output(ret);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

