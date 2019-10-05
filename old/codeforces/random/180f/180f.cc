//=============================================================
// Name        : 180f
// Creat       : Thu Jul 11 08:45:30 CST 2019
// Accept      : $ACCEPTED
// Author      : landcold7
// Description : Action speaks louder more than words
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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ans[a[i]] = x;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
