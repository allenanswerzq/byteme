/* created   : 2020-11-13 09:53:27
 * accepted  : 2020-11-13 10:46:23
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
  int N, M; cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<int>> f(N + 1, vector<int>(M + 2));
  if (A[0] == 0) {
    for (int i = 1; i <= M; i++) {
      f[0][i] = 1;
    }
  } else {
    f[0][A[0]] = 1;
  }
  for (int i = 0; i + 1 < N; i++) {
    int a = A[i];
    if (a == 0) {
      for (int j = 1; j <= M; j++) {
        add(f[i + 1][j], f[i][j]);
        if (j - 1 >= 1) add(f[i + 1][j - 1], f[i][j]);
        if (j + 1 <= M) add(f[i + 1][j + 1], f[i][j]);
      }
    }
    else {
      add(f[i + 1][a], f[i][a]);
      if (a - 1 >= 1) add(f[i + 1][a - 1], f[i][a]);
      if (a + 1 <= M) add(f[i + 1][a + 1], f[i][a]);
    }
  }
  if (A[N - 1] == 0) {
    int ans = 0;
    for (int i = 1; i <= M; i++) {
      add(ans, f[N - 1][i]);
    }
    cout << ans << "\n";
  }
  else {
    cout << f[N - 1][A[N - 1]] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
