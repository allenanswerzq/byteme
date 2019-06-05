//=============================================================
// Name        : 1075b
// Date        : Sun Jun  2 12:38:16 CST 2019
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
typedef vector<int> vi;

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n + m);
  for (int i = 0; i < n + m; ++i) {
    cin >> a[i];
  }
  vi b(n + m), driver;
  for (int i = 0; i < n + m; ++i) {
    cin >> b[i];
    if (b[i] == 1) {
      driver.push_back(a[i]);
    }
  }
  auto binary_search = [&](int ix) {
    int n = sz(driver);
    int lo = -1, hi = n;
    while (hi - lo > 1) {
      int mid = lo + (hi - lo) / 2;
      if (driver[mid] <= ix) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    const int inf = 1e9 + 7;
    int a = lo == -1 ? inf : abs(driver[lo] - ix);
    int b = hi == n ? inf : abs(driver[hi] - ix);
    return a <= b ? lo : hi;
  };
  trace(driver);
  vi cnt(m);
  for (int i = 0; i < n + m; ++i) {
    if (b[i] == 0) {
      int ix = binary_search(a[i]);
      cnt[ix]++;
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << cnt[i] << (i == m - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
