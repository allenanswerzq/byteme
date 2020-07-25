/* created   : 2020-04-07 21:53:22
 * accepted  : 2020-04-07 22:52:34
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  s = 'x' + s + 'x';
  n = s.size();
  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    ans += (a[i] == '.' && a[i + 1] == '.');
  }
  trace(s, ans);
  for (int i = 0; i < m; i++) {
    int x; char ch; cin >> x >> ch;
    trace(x, ch, s[x], s, ans);
    if (s[x] == '.' && ch != '.') {
      if (s[x - 1] != '.' && s[x + 1] != '.') {
        // x.x
      }
      else if (s[x - 1] == '.' && s[x + 1] == '.') {
        // .x.
        ans -= 2;
      }
      else {
        ans--;
      }
    }
    else if (s[x] != '.' && ch == '.') {
      if (s[x - 1] != '.' && s[x + 1] != '.') {
        // x.x
      }
      else if (s[x - 1] == '.' && s[x + 1] == '.') {
        // .x.
        ans += 2;
      }
      else {
        // xx. .xx
        ans++;
      }
    }
    s[x] = ch;
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
