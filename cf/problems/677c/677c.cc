/* created   : 2020-02-12 22:55:22
 * accepted  : 2020-02-12 23:30:29
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

int to_number(char c) {
  if ('0' <= c && c <= '9') {
    return c - '0';
  }
  else if ('A' <= c && c <= 'Z') {
    return c - 'A' + 10;
  }
  else if ('a' <= c && c <= 'z') {
    return c - 'a' + 36;
  }
  else if (c == '-') {
    return 62;
  }
  else if (c == '_') {
    return 63;
  }
  else {
    assert(false);
    return 0;
  }
}

const int mod = 1e9 + 7;

void solve() {
  string s; cin >> s;
  int n = s.size();
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    int x = to_number(s[i]);
    for (int j = 0; j < 6; j++) {
      if (!(x & (1 << j))) {
        ans = (ans * 3) % mod;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
