/* created   : 2022-02-26 11:49:37
 * accepted  : 2022-02-26 21:01:16
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int floor_two(int n) {
  int x = 0;
  while ((1 << x) < n) {
    x++;
  }
  return (1 << (x - 1));
}

void solve() {
  // 0001
  // 0010
  // 0011
  // 0100
  // 0101
  // 0110
  // 0111  7
  // 0000
  // 1000
  //
  int N; cin >> N;
  int z = floor_two(N);
  vector<int> ans;
  for (int i = 1; i <= N - 1; i++) {
    if (i == z) {
      ans.push_back(0);
    }
    ans.push_back(i);
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
