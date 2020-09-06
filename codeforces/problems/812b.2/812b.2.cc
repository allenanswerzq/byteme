/* created   : 2020-09-06 09:20:36
 * accepted  : 2020-09-06 09:51:42
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, M; cin >> N >> M;
  M += 2;
  vector<string> A(N);
  for (auto& a : A) cin >> a;
  reverse(all(A));
  vector<int> left_most(N, M - 1);
  vector<int> right_most(N);
  int max_floor = -1;
  for (int i = 0; i < N; i++) {
    for (int j = M - 1; j >= 0; j--) {
      if (A[i][j] == '1') {
        left_most[i] = j;
        max_floor = i;
      }
    }
    for (int j = 0; j < M; j++) {
      if (A[i][j] == '1') {
        right_most[i] = j;
      }
    }
  }
  trace(left_most, right_most);
  int ans = 1e9;
  for (int state = 0; state < (1 << N); state++) {
    int floor = 0, cur = 0, room = 0;
    while (floor <= max_floor) {
      if (room == 0) {
        cur += right_most[floor] - room;
        room = right_most[floor];
      }
      else {
        cur += room - left_most[floor];
        room = left_most[floor];
      }
      if (floor == max_floor) break;
      int nxt = (state & (1 << floor)) == 0 ? 0 : M - 1;
      cur += abs(nxt - room) + 1;
      room = nxt;
      floor++;
    }
    trace(N, bitset<8>(state), cur);
    ans = min(ans, cur);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
