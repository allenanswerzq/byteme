//=============================================================
// Name        : 1055b
// Date        : Sun Jun 30 16:53:09 CST 2019
// Accepted    : Sun Jun 30 21:37:37 CST 2019
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
  int n, m, l;
  cin >> n >> m >> l;
  vector<ll> a(n + 2);
  a[0] = a[n + 1] = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (a[i - 1] <= l && a[i] > l);
  }
  trace(a, ans);
  for (int i = 0; i < m; ++i) {
    int op;
    cin >> op;
    if (op == 0) {
      cout << ans << "\n";
    }
    else {
      int x, y;
      cin >> x >> y;
      if (a[x] <= l && a[x] + y > l) {
        if (a[x - 1] <= l) {
          ans++;
        }
        if (a[x + 1] > l) {
          ans--;
        }
      }
      a[x] += y;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
