//============================================================================
// Name        : b
// Date        : Mon Apr 29 22:46:40 CST 2019
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
template<typename T, typename U, typename... Args>
void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  // trace(n);
  vector<string> g(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  // trace(g);
  vector<vi> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j] != '.') {
        continue;
      }
      bool ok = 1;
      for (auto d : dirs) {
        int x = i + d[0], y = j + d[1];
        if (!(0 <= x && x < n && 0 <= y && y < n)) {
          ok = 0;
          break;
        }
        // trace(x, y);
        if (g[x][y] == '#') {
          ok = 0;
          break;
        }
      }
      if (ok) {
        g[i][j] = '#';
        for (auto d : dirs) {
          int x = i + d[0], y = j + d[1];
          g[x][y] = '#';
        }
      }
    }
  }
  // trace(g);
  int ok = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == '.') {
        ok = 0;
        break;
      }
    }
  }
  output(ok ? "YES" : "NO");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

