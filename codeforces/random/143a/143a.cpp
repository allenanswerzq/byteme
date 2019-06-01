//============================================================================
// Name        : 143a
// Date        : Tue May 21 14:02:46 CST 2019
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
  int r1, r2, c1, c2, d1, d2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      for (int k = 1; k <= 9; ++k) {
        for (int h = 1; h <= 9; ++h) {
          vi a = {i, j, k, h};
          set<int> st(all(a));
          if (sz(st) == 4) {
            if (i + j == r1 && h + k == r2 && i + k == c1 &&
                j + h == c2 && i + h == d1 && j + k == d2) {
              output(i, j);
              output(k, h);
              return;
            }
          }
        }
      }
    }
  }
  output(-1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
