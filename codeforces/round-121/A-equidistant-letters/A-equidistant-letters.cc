/* created   : 2022-02-13 19:42:22
 * accepted  : 2022-02-13 19:46:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  string S; cin >> S;
  vector<int> cnt(26);
  for (char c : S) {
    cnt[c - 'a']++;
  }
  string ans;
  for (int i = 0; i < 26; i++) {
    char c = (char)(i + 'a');
    if (cnt[i] == 1) {
      ans += c;
    }
    else if (cnt[i] == 2) {
      ans += string(2, c);
    }
  }
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
