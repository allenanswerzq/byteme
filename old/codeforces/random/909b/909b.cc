//=============================================================
// Name        : 909b
// Date        : Sun Jun 23 16:21:54 CST 2019
// Accepted    : Sun Jun 23 17:43:29 CST 2019
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
  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      for (int k = i; k <= j; ++k) {
        a[k]++;
      }
    }
  }
  cout << *max_element(a.begin(), a.end()) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
