//=============================================================
// Name        : 962b
// Date        : Sat Jun 15 17:19:13 CST 2019
// Accepted    : Sat Jun 15 18:42:38 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n && (a > 0 || b > 0); ++i) {
    if (s[i] == '.') {
      int j = i;
      while (j < n && s[j] == '.') {
        j++;
      }
      if (a < b) {
        swap(a, b);
      }
      int len = j - i;
      int x = min((len + 1) / 2, a);
      int y = min(len / 2, b);
      ans += x, a -= x;
      ans += y, b -= y;
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
