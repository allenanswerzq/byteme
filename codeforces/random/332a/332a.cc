//=============================================================
// Name        : 332a
// Date        : Tue Jul  2 10:29:22 CST 2019
// Accepted    : Tue Jul  2 10:33:49 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  trace(n, s);
  int ans = 0;
  for (int i = n; i < sz(s); i += n) {
    if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) {
      ans++;
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
