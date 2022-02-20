/* created   : 2022-02-20 11:42:04
 * accepted  : 2022-02-20 17:14:31
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 0 1 2 3 4 5 6 7
  //0001 1
  //0011 3

  //0010 2
  //0000 0
  //0100 4
  //0101 5
  //
  //0110 6
  //0111 7
  //1000 8
  //1001 9
  //
  //1010 10
  //1011 11
  //1100 12
  //1101 13
  //
  //1110 14
  //1111 15
  //
  // 1: i & (2^x - i - 1) = 0
  int N, K; cin >> N >> K;
  if (K == N - 1) {
    if (N <= 4) {
      cout << -1 << "\n";
      return;
    }
    vector<ar> ans;
    ans.push_back({1, 3});
    ans.push_back({N - 1, N - 2});
    for (int i = 2; i < N / 2; i++) {
      int a = i;
      int b = N - 1 - i;
      if (a == 3) a = 0;
      ans.push_back({a, b});
    }
    int s = 0;
    for (int i = 0; i < N / 2; i++) {
      s += (ans[i][0] & ans[i][1]);
      cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
  }
  else {
    vector<ar> ans;
    ans.push_back({N - 1, K});
    for (int i = 1; i < N / 2; i++) {
      int a = i;
      int b = N - 1 - i;
      if (a == K) a = 0;
      if (b == K) b = 0;
      ans.push_back({a, b});
    }
    int s = 0;
    for (int i = 0; i < N / 2; i++) {
      s += (ans[i][0] & ans[i][1]);
      cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
    assert(s == K);
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
