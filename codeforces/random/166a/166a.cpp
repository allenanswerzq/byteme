//============================================================================
// Name        : 166a
// Date        : Thu Apr 11 21:21:38 CST 2019
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

struct Node {
  int p, t;
  friend dbstream& operator<<(dbstream& os, Node& a) {
    os << a.p << " " << a.t << "\n";
    return os;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<Node> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].p >> a[i].t;
  }
  sort(all(a), [](Node& a, Node& b){
    if (a.p == b.p) {
      return a.t < b.t;
    } else {
      return a.p > b.p;
    }
  });
  trace(a);
  k -= 1;
  int ret = 1;
  for (int i = k + 1; i < n; ++i) {
    if (a[i].p == a[k].p && a[i].t == a[k].t) {
      ++ret;
    }
  }
  for (int i = k - 1; i >= 0; --i) {
    if (a[i].p == a[k].p && a[i].t == a[k].t) {
      ++ret;
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

