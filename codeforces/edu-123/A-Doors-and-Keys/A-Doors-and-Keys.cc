/* created   : 2022-03-21 20:53:40
 * accepted  : 2022-03-21 20:55:57
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
    if ('A' <= c && c <= 'Z') {
      if (!cnt[c - 'A']) {
        cout << "NO\n";
        return;
      }
    }
    else {
      cnt[c - 'a']++;
    }
  }
  cout << "YES\n";
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
