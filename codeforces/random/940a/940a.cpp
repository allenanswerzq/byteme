//=============================================================
// Name        : 940a
// Date        : Fri Jun 14 16:03:04 CST 2019
// Accepted    : Fri Jun 14 16:17:39 CST 2019
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
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  const int inf = 1e9 + 7;
  int ans = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int dia = a[j] - a[i];
      int tmp = i + (n - j - 1);
      if (dia <= d) {
        ans = min(ans, tmp);
      }
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
