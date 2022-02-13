/* created   : 2022-02-13 19:51:21
 * accepted  : 2022-02-13 20:14:07
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  string S; cin >> S;
  // 12348799671234990012
  // 12348799131234990012
  // 1234879967123418
  // 12348718
  // 33487
  // 15487
  // 12787
  // 123127
  // 123415
  //
  // 12343
  // 3343
  // 1543
  // 1273
  int n = S.size();
  for (int i = n - 2; i >= 0; i--) {
    char a = S[i] - '0';
    char b = S[i + 1] - '0';
    if (a + b >= 10) {
      S[i] = (char)((a + b) / 10) + '0';
      S[i + 1] = (char)((a + b) % 10) + '0';
      cout << S << "\n";
      return;
    }
  }
  int i = 0;
  char a = S[i] - '0';
  char b = S[i + 1] - '0';
  char c = (char)((a + b) % 10) + '0';
  string ans;
  ans += c;
  ans += S.substr(2);
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
