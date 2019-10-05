//=============================================================
// Name        : 617b
// Date        : Wed Jun  5 10:56:36 CST 2019
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
  vector<int> a(n);
  bool ok = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 1) {
      ok = 1;
    }
  }
  if (!ok) {
    cout << 0 << "\n";
    return;
  }
  trace(a);
  ll ret = 1;
  int pr = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      if (pr != -1) {
        ret *= (i - pr);
      }
      pr = i;
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
