/* created   : 2019-08-25 20:28:56
 * accepted  : 2019-08-25 21:25:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<vector<char>> v(4, vector<char>(n));
  char c = 'a';
  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      if (c > 'z') {
        c = 'a';
      }
      v[0][i] = c;
      v[0][i + 1] = c++;
      if (c > 'z') {
        c = 'a';
      }
      v[1][i] = c;
      v[1][i + 1] = c++;
    }
    c = v[1][0] + 1;
    if (c > 'z') c = 'a';
    v[2][0] = c;
    v[3][0] = c++;
    for (int i = 1; i < n && i + 1 < n; i += 2) {
      if (c > 'z') c = 'a';
      v[2][i] = c;
      v[2][i + 1] = c++;
      if (c > 'z') c = 'a';
      v[3][i] = c;
      v[3][i + 1] = c++;
    }
    if (c > 'z') c = 'a';
    v[2][n - 1] = c;
    v[3][n - 1] = c;
    swap(v[2], v[3]);
  }
  else {
    for (int i = 0; i < n && i + 1 < n; i += 2) {
      if (c > 'z') {
        c = 'a';
      }
      v[0][i] = c;
      v[0][i + 1] = c++;
      if (c > 'z') {
        c = 'a';
      }
      v[1][i] = c;
      v[1][i + 1] = c++;
    }
    if (c > 'z') {
      c = 'a';
    }
    v[0][n - 1] = c;
    v[1][n - 1] = c++;
    if (c > 'z') {
      c = 'a';
    }
    c = v[1][0] + 1;
    if (c > 'z') {
      c = 'a';
    }
    v[2][0] = c;
    v[3][0] = c++;
    for (int i = 1; i < n && i + 1 < n; i += 2) {
      if (c > 'z') {
        c = 'a';
      }
      v[2][i] = c;
      v[2][i + 1] = c++;
      if (c > 'z') {
        c = 'a';
      }
      v[3][i] = c;
      v[3][i + 1] = c++;
    }
    swap(v[2], v[3]);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cout << v[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
