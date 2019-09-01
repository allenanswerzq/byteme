/* created   : 2019-08-10 21:16:56
 * accepted  : 2019-08-10 21:56:34
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  if (n < 3) {
    cout << -1 << '\n';
    return;
  }
  else if (n == 3) {
    cout << 210 << '\n';
    return;
  }
  int x = 1;
  for (int i = 0; i < n - 1; i++) {
    x = (10 * x) % 210;
  }
  int r = 210 - x;
  string sr = to_string(r);
  int nr = sr.size();
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << "1";
    }
    else if (i < n - nr) {
      cout << "0";
    }
    else {
      cout << sr[i - (n - nr)];
    }
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
