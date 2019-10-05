//=============================================================
// Name        : 989b
// Date        : Tue Jun 18 15:31:09 CST 2019
// Accepted    : Tue Jun 18 16:17:00 CST 2019
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
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  for (int i = 0; i + p < n; ++i) {
    bool ok = 0;
    for (int j = 0; j < p && i + p + j < n; ++j) {
      int a = i + j, b = i + p + j;
      if (s[a] != s[b]) {
        ok = 1;
        if (s[a] == '.') {
          s[a] = (s[b] == '1' ? '0' : '1');
        } else if (s[b] == '.') {
          s[b] = (s[a] == '1' ? '0' : '1');
        }
      } else if (s[a] == s[b] && s[a] == '.') {
        ok = 1;
        s[a] = '0';
        s[b] = '1';
      }
    }
    if (ok) {
      for (int j = 0; j < n; ++j) {
        if (s[j] == '.') {
          s[j] = '0';
        }
      }
      cout << s << endl;
      return;
    }
  }
  cout << "No" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
