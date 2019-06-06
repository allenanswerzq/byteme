//=============================================================
// Name        : 750b
// Date        : Wed Jun  5 16:02:39 CST 2019
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
  ll y = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    string dir;
    cin >> d >> dir;
    if (y > 0 || y < -20000) {
      cout << "NO\n";
      return;
    }
    if (y == 0 && dir != "South") {
      cout << "NO\n";
      return;
    }
    if (y == -20000 && dir != "North") {
      cout << "NO\n";
      return;
    }
    if (dir == "South") {
      y -= d;
    } else if (dir == "North") {
      y += d;
    }
  }
  cout << (y == 0 ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
