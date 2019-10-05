//=============================================================
// Name        : 787b
// Date        : Mon Jun 24 15:24:38 CST 2019
// Accepted    : Mon Jun 24 15:48:58 CST 2019
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
  int n, m;
  cin >> n >> m;
  bool ans = 0;
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    set<int> st;
    bool ok = 1;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      if (st.count(-x)) {
        ok = 0;
      }
      st.insert(x);
    }
    ans |= ok;
  }
  cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
