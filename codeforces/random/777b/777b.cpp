//=============================================================
// Name        : 777b
// Date        : Wed Jun 12 20:00:06 CST 2019
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
  string a, b;
  cin >> a >> b;
  int mi = 0;
  vector<bool> was(n);
  sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    bool ok = 0;
    for (int j = 0; j < n; ++j) {
      if (!was[j] && b[j] >= a[i]) {
        was[j] = 1;
        ok = 1;
        break;
      }
    }
    if (!ok) {
      mi++;
    }
  }
  int mx = 0;
  was = vector<bool>(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!was[j] && b[j] > a[i]) {
        was[j] = 1;
        mx++;
        break;
      }
    }
  }
  cout << mi << "\n";
  cout << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
