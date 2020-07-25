/* created   : 2020-02-10 21:09:31
 * accepted  : 2020-02-10 22:15:42
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
  vector<string> a(2);
  for (int i = 0; i < 2; i++) {
    cin >> a[i];
  }
  int n = a[0].size();
  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    int cur = (a[0][i] == '0') + (a[1][i] == '0');
    int nxt = (a[0][i + 1] == '0') + (a[1][i + 1] == '0');
    if (cur == 2 && nxt == 2) {
      a[0][i] = 'X';
      a[1][i] = 'X'; a[1][i + 1] = 'X';
      ans++;
    }
    else if (cur == 1 && nxt == 2) {
      // x0
      // 00
      a[0][i] = 'X';
      a[1][i] = 'X';
      a[0][i + 1] = 'X';
      a[1][i + 1] = 'X';
      ans++;
    }
    else if (cur == 2 && nxt == 1) {
      // 0x
      // 00
      a[0][i] = 'X';
      a[1][i] = 'X';
      a[0][i + 1] = 'X';
      a[1][i + 1] = 'X';
      ans++;
    }
    else {
    }
  }
  trace(a);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
