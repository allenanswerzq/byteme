/*
 * created   : 2019-07-30 18:50:16
 * accepted  : 2019-07-30 21:35:27
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
  string a, b;
  cin >> a >> b;
  int na = (int) a.size();
  int nb = (int) b.size();
  auto check = [&](int x) {
    string com = a.substr(0, x);
    for (int i = 0; i + x <= na; i += x) {
      if (com != a.substr(i, x)) {
        return false;
      }
    }
    for (int i = 0; i + x <= nb; i += x) {
      if (com != b.substr(i, x)) {
        return false;
      }
    }
    return true;
  };
  int ans = 0;
  for (int len = 1; len <= min(na, nb); len++) {
    if (na % len == 0 && nb % len == 0) {
      if (check(len)) {
        ans++;
      }
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
