/* created   : 2021-01-16 16:43:21
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void amin(int& a, int b) { a = min(a, b); }

void solve() {
// 2 5
// 6 10
// 4 7
// 9 10
  // 1234567890
  //  ----
  //      -----
  //    ----
  //         --
  const int Z = 1e6;
  const int H = 20;
  vector<vector<int>> nxt;
  nxt.resize(Z + 1, vector<int>(H + 1, Z));
  int N, Q; cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    amin(nxt[a][0], b);
  }
  // -----|--
  //  ----|---
  //    --|
  // First time any movie ends if we start to watch at time i
  for (int i = Z; i >= 1; i--) {
    amin(nxt[i - 1][0], nxt[i][0]);
  }
  for (int j = 1; j <= H; j++) {
    for (int i = 0; i <= Z; i++) {
      int p = nxt[i][j - 1];
      nxt[i][j] = nxt[p][j - 1];
    }
  }
  // Binary lifting
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    int ans = 0;
    for (int j = H; j >= 0; j--) {
      if (nxt[a][j] <= b) {
        ans ^= (1 << j);
        a = nxt[a][j];
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
