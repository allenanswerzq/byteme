//=============================================================
// Name        : 922b
// Date        : Wed Jun 12 21:56:18 CST 2019
// Accepted    : Wed Jun 12 22:15:09 CST 2019
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
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int k = i ^ j;
      trace(i, j, k);
      if (1 <= k && k <= n) {
        vector<int> a = {i, j, k};
        sort(a.begin(), a.end());
        if (a[0] + a[1] > a[2] && a[2] - a[1] < a[0]) {
          ans++;
        }
      }
    }
  }
  cout << ans / 3 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
