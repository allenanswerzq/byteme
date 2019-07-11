//=============================================================
// Name        : 288a
// Date        : Thu Jun 20 17:17:22 CST 2019
// Accepted    : Thu Jun 20 17:51:40 CST 2019
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
  int n, k;
  cin >> n >> k;
  if ((k > n) || (k == 1 && n > 1)) {
    cout << -1 << "\n";
    return;
  }
  if (k == 1 && n == 1) {
    cout << "a" << "\n";
    return;
  }
  string ans(n, 'a');
  k = k - 2;
  for (int i = 0; i <= n - k; i += 2) {
    ans[i] = 'a';
    ans[i + 1] = 'b';
  }
  char c = 'c';
  for (int i = n - k; i < n ; ++i) {
    ans[i] = c++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
