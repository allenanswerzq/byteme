/* created   : 2021-11-22 08:33:28
 * accepted  : 2021-11-23 08:47:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, K; cin >> N >> K;
  // a ab ac ad b bc bd c cd d
  string ans;
  while (ans.size() < N) {
    for (int i = 0; i < K && ans.size() < N; i++) {
      ans += (char)('a' + i);
      for (int j = i + 1; j < K && ans.size() < N; j++) {
        ans += (char)('a' + i);
        if (ans.size() < N) {
          ans += (char)('a' + j);
        }
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
