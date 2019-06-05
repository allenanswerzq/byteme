//=============================================================
// Name        : 255b
// Date        : Sat Jun  1 21:58:21 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (int i = 0; i < sz(s); ++i) {
    if (s[i] == 'x') {
      a++;
    } else {
      b++;
    }
  }
  int mi = min(a, b);
  a = a - mi;
  b = b - mi;
  if (a > 0) {
    cout << string(a, 'x') << '\n';
  } else {
    cout << string(b, 'y') << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  // cin.tie(0);
  solve();
  return 0;
}
