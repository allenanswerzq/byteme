//============================================================================
// Name        : 431b
// Date        : Mon May 20 09:32:57 CST 2019
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
  vector<vi> g(6, vi(6));
  for (int i = 1; i <= 5; ++i) {
    for (int j = 1; j <= 5; ++j) {
      cin >> g[i][j];
    }
  }
  vi a = {1, 2, 3, 4, 5};
  int ret = 0;
  do {
    int tmp = (g[a[0]][a[1]] + g[a[1]][a[0]] + g[a[2]][a[3]] + g[a[3]][a[2]])
            + (g[a[1]][a[2]] + g[a[2]][a[1]] + g[a[3]][a[4]] + g[a[4]][a[3]])
            + (g[a[2]][a[3]] + g[a[3]][a[2]])
            + (g[a[3]][a[4]] + g[a[4]][a[3]]);
    ret = max(ret, tmp);
  } while (next_permutation(all(a)));
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
