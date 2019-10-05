//=============================================================
// Name        : 1040b
// Date        : Wed Jun 19 15:34:20 CST 2019
// Accepted    : Wed Jun 19 16:55:41 CST 2019
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
  for (int i = 1; i <= min(n, k + 1); ++i) {
    int center = i;
    vector<int> ans;
    while (center <= n) {
      ans.push_back(center);
      if (n - center <= k) {
        int na = (int) ans.size();
        cout << na << "\n";
        for (int j = 0; j < na; ++j) {
          cout << ans[j] << (j == na - 1 ? "\n" : " ");
        }
        return;
      }
      center += 2 * k + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
