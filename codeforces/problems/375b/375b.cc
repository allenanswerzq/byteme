/* created   : 2020-09-07 23:39:06
 * accepted  : 2020-09-08 08:14:09
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int NX = 5007;
char A[NX][NX];
int f[NX][NX];

void solve() {
  int N, M; cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    scanf("%s", A[i] + 1);
  }
  // -----|
  //     -|
  //      |
  //   ---|
  //     _|
  //  ----|
  vector<vector<int>> cnt(M + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (A[i][j] == '1') {
        f[i][j] = f[i][j - 1] + 1;
        cnt[j].push_back(f[i][j]);
      }
    }
  }
  // 2 2 3 4 5
  trace(cnt);
  int ans = 0;
  for (int j = 1; j <= M; j++) {
    int n = cnt[j].size();
    sort(all(cnt[j]));
    int k = 0;
    for (auto& x : cnt[j]) {
      ans = max(ans, x * (n - k++));
    }
  }
  cout << ans << "\n";
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
