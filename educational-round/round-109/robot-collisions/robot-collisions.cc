/* created   : 2021-09-12 11:11:21
 * accepted  : 2021-10-17 16:11:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M; cin >> N >> M;
  vector<ar> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i][0];
  }
  for (int i = 0; i < N; i++) {
    char ch; cin >> ch;
    A[i][1] = (ch == 'L' ? -1 : 1);
  }
  vector<int> order(N);
  iota(all(order), 0);
  sort(all(order), [&A](int x, int y) {
    return A[x][0] < A[y][0];
  });
  trace(order);
  vector<int> ans(N, -1);
  vector<vector<int>> stk(2);
  for (int i : order) {
    int p = A[i][0] % 2;
    if (A[i][1] == -1) { // 'L' <--
      if (stk[p].empty()) {
        stk[p].push_back(i);
      }
      else {
        // -->  <--
        // <--  <--
        int j = stk[p].back();
        stk[p].pop_back();
        int t = (A[j][1] == -1 ? -A[j][0] : A[j][0]);
        ans[i] = ans[j] = (A[i][0] - t) / 2;
      }
    }
    else {
      // 'R' -->
      // It needs to wait for canceling with a Left robot first
      stk[p].push_back(i);
    }
  }
  for (int p = 0; p < 2; p++) {
    while (stk[p].size() >= 2) {
      int i = stk[p].back();
      stk[p].pop_back();
      int j = stk[p].back();
      stk[p].pop_back();
      assert(A[i][1] == 1);
      // assert(A[j][1] == 1);
      // -->  -->
      // <--  -->
      int t = A[j][1] == 1 ? A[j][0] : -A[j][0];
      ans[i] = ans[j] = (M - A[i][0] + M - t) / 2;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
