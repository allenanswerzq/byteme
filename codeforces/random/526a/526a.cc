//=============================================================
// Name        : 526a
// Date        : Thu Jun 27 11:19:20 CST 2019
// Accepted    : Thu Jun 27 11:22:39 CST 2019
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
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      for (int j = 1; j < 100; ++j) {
        int k = i, cnt = 0;
        while (k < n && s[k] == '*') {
          k += j;
          cnt++;
        }
        if (cnt == 5) {
          cout << "yes" << "\n";
          return;
        }
      }
    }
  }
  cout << "no" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
