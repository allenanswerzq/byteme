//=============================================================
// Name        : 1038c
// Date        : Sun Jun  9 16:51:50 CST 2019
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
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  trace(a, b);
  ll sa = 0, sb = 0;
  int ia = n - 1, ib = n - 1;
  while (ia >= 0 || ib >= 0) {
    trace(ia, ib);
    if ((ia >= 0 && ib >= 0 && a[ia] >= b[ib])
        || (ib < 0 && ia >= 0)) {
      sa += a[ia--];
    } else {
      ib--;
    }
    if ((ia >= 0 && ib >= 0 && a[ia] <= b[ib])
        || (ia < 0 && ib >= 0)) {
      sb += b[ib--];
    } else {
      ia--;
    }
  }
  trace(sa, sb);
  cout << (sa - sb) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
