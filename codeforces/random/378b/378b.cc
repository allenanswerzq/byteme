//=============================================================
// Name        : 378b
// Date        : Mon Jul  1 10:17:34 CST 2019
// Accepted    : Mon Jul  1 10:33:20 CST 2019
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  vector<bool> wa(n), wb(n);
  int p = 0, q = 0;
  for (int i = 0; i < n; ++i) {
    if (a[p].x < a[q].y) {
      wa[p++] = 1;
    }
    else {
      wb[q++] = 1;
    }
  }
  for (int i = 0; i < n / 2; ++i) {
    wa[i] = 1;
    wb[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << wa[i] << (i == n - 1 ? "\n" : "");
  }
  for (int i = 0; i < n; ++i) {
    cout << wb[i] << (i == n - 1 ? "\n" : "");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
