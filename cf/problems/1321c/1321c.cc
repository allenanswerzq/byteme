/* created   : 2020-04-23 22:55:49
 * accepted  : 2020-04-23 23:35:41
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  for (char ch = 'z'; ch >= 'a'; ch--) {
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] != ch) {
        continue;
      }
      bool ok = false;
      if (i >= 1 && s[i - 1] + 1 == s[i]) {
        ok = true;
      }
      if (i + 1 < (int) s.size() && s[i] == s[i + 1] + 1) {
        ok = true;
      }
      if (ok) {
        s.erase(s.begin() + i);
        i--;
      }
    }
  }
  cout << n - (int) s.size() << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
