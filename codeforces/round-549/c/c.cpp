//============================================================================
// Name        : c
// Date        : Mon Apr  8 11:07:07 CST 2019
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

vvi g;
vi order;
vi color;
void dfs(int u) {
  bool ok = 1;
  for (auto& v : g[u]) {
    if (color[v] == 0) {
      ok = 0;
      break;
    }
  }
  if (ok && color[u]) {
    order.pb(u);
  }
  for (auto v : g[u]) {
    dfs(v);
  }
}

void solve() {
  int n; cin >> n;
  int root = 0;
  g = vvi(n);
  color = vi(n);
  for (int i = 0; i < n; ++i) {
    int p, c;
    cin >> p >> c;
    color[i] = c;
    if (p == -1) {
      root = i;
    } else {
      g[--p].pb(i);
    }
  }
  // trace(color, g);
  dfs(root);
  // trace(order);
  if (sz(order) == 0) {
    output(-1);
    return;
  }
  sort(all(order));
  for (int i = 0; i < sz(order); ++i) {
    order[i] += 1;
  }
  par(order, 0, sz(order), 0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

