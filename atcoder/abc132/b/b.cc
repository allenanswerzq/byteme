//=============================================================
// Name        : b
// Date        : Wed Jul  3 22:42:36 CST 2019
// Accepted    : Wed Jul  3 22:43:40 CST 2019
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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    int x = a[i - 1], y = a[i + 1];
    if (x > y) {
      swap(x, y);
    }
    if (x < a[i] && a[i] < y) {
      ans++;
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
