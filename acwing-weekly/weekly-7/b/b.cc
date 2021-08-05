/* created   : 2021-08-03 22:27:18
 * accepted  : 2021-08-03 22:57:25
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 43210
  // 00011 --> 1
  // 00101 --> 2
  // 00110 --> 3
  // 01001 --> 4
  // 01010 --> 5
  // 01100 --> 6
  // 10001
  // 10010
  // 10100
  // 11000
  // 1 + 2 + 3 + 4 = 10
  ll N, K; cin >> N >> K;
  // 1 + 2 + 3 + ... > K
  // n * (n + 1) / 2 > K
  ll ceil = -1;
  for (int i = 1; i <= N; i++) {
    if (i * 1ll * (i + 1) >= 2 * 1ll * K) {
      ceil = i;
      break;
    }
  }
  // 011
  // 101
  assert(ceil >= 1);
  int offset = K - ceil * (ceil - 1) / 2;
  trace(N, ceil, offset, K);
  assert(offset - 1 < ceil);
  string ans;
  for (int i = 0; i < N; i++) {
    if (i == offset - 1) {
      ans += 'b';
    }
    else if (i == ceil) {
      ans += 'b';
    }
    else {
      ans += 'a';
    }
  }
  reverse(all(ans));
  cout << ans << "\n";
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
