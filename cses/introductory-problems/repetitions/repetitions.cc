/* created   : 2020-10-29 09:36:09
 * accepted  : 2020-10-29 09:44:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  string S; cin >> S;
  int ans = 0;
  char c = '@';
  for (int i = 0, j = 0; i < S.size(); i++) {
    if (i == j) c = '@';
    while (j < S.size() && (c == '@' || S[j] == c)) {
      if (c == '@') c = S[j];
      j++;
    }
    ans = max(ans, j - i);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
