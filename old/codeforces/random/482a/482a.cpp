//=============================================================
// Name        : 482a
// Date        : Fri Jun  7 15:14:54 CST 2019
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
  int n, k;
  cin >> n >> k;
  int lo = 1, hi = n;
  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    if (i % 2 == 0) {
      ans.push_back(lo++);
    } else {
      ans.push_back(hi--);
    }
  }
  if (k % 2 == 0) {
    for (int i = hi; sz(ans) < n; --i) {
      ans.push_back(i);
    }
  } else {
    for (int i = lo; sz(ans) < n; ++i) {
      ans.push_back(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
