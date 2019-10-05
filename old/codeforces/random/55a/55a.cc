//=============================================================
// Name        : 55a
// Date        : Sun Jul  7 09:21:09 CST 2019
// Accepted    : Sun Jul  7 09:30:50 CST 2019
// Author      : landcold7
// Description : Action speaks louder more than words
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
  vector<bool> was(n);
  was[0] = 1;
  int k = 1, cur = 0;
  for (int i = 0; i < 10000; ++i) {
    int nxt = (cur + k) % n;
    was[nxt] = 1;
    cur = nxt;
    k++;
  }
  trace(was);
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    if (was[i] == 0) {
      ok = 0;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
