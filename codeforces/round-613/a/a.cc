/* created   : 2020-01-10 22:04:18
 * accepted  : 2020-01-10 22:08:35
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int a = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      a++;
    }
  }
  cout << (n - a) + a + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
