/* created   : 2020-02-04 21:39:26
 * accepted  : 2020-02-04 21:50:29
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
  int n, m; cin >> n >> m;
  string s;
  for (int i = 0; i < m; i++) {
    s += (char) ('a' + i);
  }
  char ch = s.back();
  int k = 1;
  while ((int) s.size() < n) {
    s += (char)('a' + (ch - 'a' - k) % 26);
    k ^= 1;
  }
  cout << s << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
