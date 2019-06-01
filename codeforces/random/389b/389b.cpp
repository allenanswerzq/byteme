//============================================================================
// Name        : 389b
// Date        : Tue May 21 18:47:51 CST 2019
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
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pii> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == '#') {
        bool ok = 1;
        for (auto d : dir) {
          int x = i + d.x;
          int y = j + d.y;
          if (!(0 <= x && x < n && 0 <= y && y < n && a[x][y] == '#')) {
            ok = 0;
            break;
          }
        }
        if (!ok) {
          continue;
        }
        a[i][j] = '@';
        for (auto d : dir) {
          int x = i + d.x;
          int y = j + d.y;
          a[x][y] = '@';
        }
      }
    }
  }
  trace(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == '#') {
        output("NO");
        return;
      }
    }
  }
  output("YES");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
