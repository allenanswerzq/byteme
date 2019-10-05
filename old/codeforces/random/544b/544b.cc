/*
 * created   : 2019-07-24 23:16:47
 * accepted  : 2019-07-24 23:28:44
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> a(n, string(n, 'L'));
  int turn = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = (turn ? 0 : 1); j < n; j += 2) {
      a[i][j] = 'S';
    }
    turn ^= 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 'L' && k > 0) {
        k--;
      }
      else if (k == 0) {
        a[i][j] = 'S';
      }
    }
  }
  if (k > 0) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << (j == n - 1 ? "\n" : "");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
