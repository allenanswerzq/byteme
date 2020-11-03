/* created   : 2020-11-02 21:39:31
 * accepted  : 2020-11-03 14:18:41
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

int ans = 0;

void dfs(vector<string>& A, int u, int col, int up, int down) {
  if (u == -1) {
    ans++;
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (A[u][i] == '*') continue;
    if ((col >> i) & 1) continue;
    if ((up >> (u + i)) & 1) continue;
    if ((down >> (u - i + 8)) & 1) continue;
    col += 1 << i;
    up += 1 << (u + i);
    down += 1 << (u - i + 8);
    dfs(A, u - 1, col, up, down);
    col -= 1 << i;
    up -= 1 << (u + i);
    down -= 1 << (u - i + 8);
  }
}

void solve() {
  vector<string> A(8);
  for (int i = 0; i < 8; i++) {
    cin >> A[i];
  }
  dfs(A, 7, 0, 0, 0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
