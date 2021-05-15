/* created   : 2020-11-13 10:51:02
 * accepted  : 2020-11-13 11:06:03
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 5200;
int f[N][N];

void solve() {
  string A, B; cin >> A >> B;
  // f[i][j] = min f[i - 1][j - 1] if (A[i] == B[j])
  //         = min f[i - 1][j], f[i][j - 1]
  for (int i = 0; i <= A.size(); i++) {
    f[i][0] = i;
  }
  for (int j = 0; j <= B.size(); j++) {
    f[0][j] = j;
  }
  for (int i = 1; i <= A.size(); i++) {
    for (int j = 1; j <= B.size(); j++) {
      f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
      f[i][j] = min(f[i][j], f[i - 1][j - 1] + (A[i - 1] != B[j - 1]));
    }
  }
  trace(mt(f, A.size(), B.size()));
  cout << f[A.size()][B.size()] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
