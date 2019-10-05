/*
 * creat   : 2019-07-20 09:02:26
 * accept  : 2019-07-20 09:05:16
 * author  : landcold7
 */
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
  int mi = (1 << 30);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      cur += abs(a[i] - a[j]);
    }
    if (cur < mi) {
      ans = i;
      mi = cur;
    }
  }
  trace(mi, ans + 1);
  cout << ans + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
