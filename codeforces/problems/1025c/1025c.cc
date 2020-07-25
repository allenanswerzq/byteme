/* created   : 2020-05-04 16:33:56
 * accepted  : 2020-05-04 16:43:43
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s += s;
  trace(s);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    // Note: make a cycle as a chain and use each inteval
    // with length of n to do your opertions.
    while (j + 1 < i + n && s[j + 1] != s[j]) {
      j++;
    }
    if (j - i + 1 > 0) {
      trace(i, j);
      ans = max(ans, j - i + 1);
      i = j;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
