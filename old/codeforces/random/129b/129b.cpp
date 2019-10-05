//============================================================================
// Name        : 129b
// Date        : Wed May 22 09:26:00 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> void output(T t) { cout << t << "\n"; }
template<typename T, typename U, typename... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n, m;
  cin >> n >> m;
  vi deg(n);
  vector<vi> g(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    deg[x]++, deg[y]++;
    g[x].pb(y);
    g[y].pb(x);
  }
  trace(deg, g);
  int ret = 0;
  while (1) {
    vi kick;
    for (int i = 0; i < n; ++i) {
      if (deg[i] == 1) {
        kick.pb(i);
      }
    }
    trace(kick);
    if (sz(kick) == 0) {
      break;
    }
    for (auto t : kick) {
      deg[t]--;
      for (auto v : g[t]) {
        deg[v]--;
      }
    }
    ret++;
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
