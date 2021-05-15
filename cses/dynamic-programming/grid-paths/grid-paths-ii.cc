/* created   : 2020-11-12 20:10:51
 * accepted  : 2020-11-12 20:20:00
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

void solve() {
  int N; cin >> N;
  vector<string> A(N);
  for (string& a : A) {
    cin >> a;
  }
  vector<vector<int>> f(N, vector<int>(N));
  f[N - 1][N - 1] = (A[N - 1][N - 1] == '.');
  for (int i = N - 1; i >= 0; i--) {
    for (int j = N - 1; j >= 0; j--) {
      if (A[i][j] == '*') {
        f[i][j] = 0;
        continue;
      }
      if (i + 1 < N && A[i + 1][j] == '.') {
        add(f[i][j], f[i + 1][j]);
      }
      if (j + 1 < N && A[i][j + 1] == '.') {
        add(f[i][j], f[i][j + 1]);
      }
    }
  }
  cout << f[0][0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
