//=============================================================
// Name        : 92b
// Date        : Tue Jul  2 16:57:09 CST 2019
// Accepted    : Tue Jul  2 21:21:11 CST 2019
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

template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

void solve() {
  string s;
  cin >> s;
  int ans = 0;
  while (sz(s) > 1) {
    while (s.back() == '0') {
      s.pop_back();
      ans++;
    }
    if (sz(s) == 1) {
      break;
    }
    int i = sz(s) - 1;
    while (i >= 0 && s[i] == '1') {
      s[i--] = '0';
    }
    if (i > 0) {
      s[i] = '1';
    }
    else {
      s.insert(s.begin(), '1');
    }
    ans++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
