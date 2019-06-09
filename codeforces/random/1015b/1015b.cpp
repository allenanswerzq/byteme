//=============================================================
// Name        : 1015b
// Date        : Sat Jun  8 16:50:34 CST 2019
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
  string a, b;
  cin >> a >> b;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      int ix = -1;
      for (int j = i + 1; j < n; ++j) {
        if (a[j] == b[i]) {
          ix = j;
        }
      }
      if (ix == -1) {
        cout << ix << "\n";
        return;
      }
      for (int j = ix - 1; j >= i; --j) {
        swap(a[j], a[j + 1]);
        ans.push_back(j);
      }
    }
  }
  assert(a == b);
  int m = sz(ans);
  cout << m << "\n";
  for (int i = 0; i < m; ++i) {
    cout << ans[i] + 1 << (i == m - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
