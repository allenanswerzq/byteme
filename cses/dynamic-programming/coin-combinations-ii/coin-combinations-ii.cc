/* created   : 2020-11-12 16:48:24
 * accepted  : 2020-11-12 18:09:48
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void solve1() {
  int N, X; cin >> N >> X;
  vector<int> C(N);
  for (int& c : C) {
    cin >> c;
  }
  vector<int> f(X + 1);
  f[0] = 1;
  for (int c : C) {
    //  [0 1 2 3 4 5 6 7 8 9]
    //  [1   1   1   1   1  ]
    //  [1   1 1 1 1 2 1 2 1]
    for (int i = 1; i <= X; i++) {
      if (i - c >= 0) {
        add(f[i], f[i - c]);
      }
    }
  }
  cout << f[X] << "\n";
}

void solve() {
  int N, X; cin >> N >> X;
  vector<int> C(N);
  for (int& c : C) {
    cin >> c;
  }
  // f[i][x] = f[i - 1][x] + f[i][x - ci]
  vector<vector<int>> f(N + 1, vector<int>(X + 1));
  f[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= X; j++) {
      f[i][j] = f[i - 1][j];
      int c = C[i - 1];
      if (j >= c) {
        add(f[i][j], f[i][j - c]);
      }
    }
  }
  cout << f[N][X] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
