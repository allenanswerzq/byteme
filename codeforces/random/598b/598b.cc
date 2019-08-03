/*
 * creat   : 2019-07-18 22:03:18
 * accept  : 2019-07-18 22:59:29
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
  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    l--, r--;
    int x = (r - l + 1);
    k %= x;
    rotate(s.begin() + l, s.begin() + l + (x - k), s.begin() + r + 1);
  }
  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
