//=============================================================
// Name        : 899b
// Date        : Thu Jun 27 10:52:28 CST 2019
// Accepted    : Thu Jun 27 10:59:24 CST 2019
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
  vector<int> a(n);
  int x = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    x += (a[i] == 29);
  }
  if (x >= 2) {
    cout << "No" << "\n";
    return;
  }
  vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int i = 0; i < 12 ; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      int cur = days[(i + j) % 12];
      if (a[j] == cur || (a[j] == 29 && cur == 28)) {
        cnt++;
      }
    }
    if (cnt == n) {
      cout << "Yes" << "\n";
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
