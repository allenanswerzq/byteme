/* created   : 2021-10-19 07:35:08
 * accepted  : 2021-10-23 15:39:43
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void amin(int & a, int b) { a = min(a, b); }

void solve() {
  int N; cin >> N;
  vector<int> A(N + 1);
  vector<int> P(1);
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    if (A[i] == 1) {
      P.push_back(i);
    }
    cnt += (A[i] == 1);
  }
  trace(A, P, cnt);
  const int INF = 1e9 + 7;
  vector<vector<int>> f(N + 1, vector<int>(N + 1, INF));
  for (int i = 0; i <= N; i++) {
    f[i][0] = 0;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= cnt; j++) {
      if (A[i] == 1) {
        amin(f[i][j], f[i - 1][j]);
      }
      else {
        // choices 1: chose current position with the jth starting positioin
        assert(P[j] != i);
        amin(f[i][j], f[i - 1][j - 1] + abs(P[j] - i));
        trace(i, j, f[i][j]);
        // choices 2: do not chose current position to match
        amin(f[i][j], f[i - 1][j]);
      }
    }
  }
  trace(f);
  cout << f[N][cnt] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
