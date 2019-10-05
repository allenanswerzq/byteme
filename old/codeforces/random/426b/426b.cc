//=============================================================
// Name        : 426b
// Date        : Tue Jul  2 10:42:00 CST 2019
// Accepted    : Tue Jul  2 10:55:46 CST 2019
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
  int n, m;
  cin >> n >> m;
  string ws;
  getline(cin, ws);
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    getline(cin, a[i]);
  }
  int ans = n;
  while (n >= 2 && n % 2 == 0) {
    vector<string> lo(n / 2), hi(n / 2);
    for (int i = 0; i < n; ++i) {
      if (i < n / 2) {
        lo[i] = a[i];
      }
      else {
        hi[i - n / 2] = a[i];
      }
    }
    reverse(hi.begin(), hi.end());
    trace(lo, hi, n);
    if (lo == hi) {
      ans = n / 2;
      a = lo;
      n = sz(a);
    }
    else {
      break;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
