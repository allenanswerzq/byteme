//=============================================================
// Name        : 370b
// Date        : Sat Jul  6 10:41:41 CST 2019
// Accepted    : Sat Jul  6 11:00:54 CST 2019
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
  vector<vector<int>> a(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  auto check = [&](int x, int y) {
    if (sz(a[x]) < sz(a[y])) {
      return false;
    }
    set<int> st(a[x].begin(), a[x].end());
    for (int i = 0; i < sz(a[y]); ++i) {
      if (!st.count(a[y][i])) {
        return false;
      }
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    bool ok = 1;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        if (check(i, j)) {
          ok = 0;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
