/*
 * Name        : 54a
 * Creat       : Thu Jul 11 09:51:40 CST 2019
 * Accept      : Thu Jul 11 09:51:43 CST 2019
 * Author      : landcold7
 * Description : Action speaks louder more than words
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
  int n, k, c;
  cin >> n >> k >> c;
  vector<int> a(c);
  for (int i = 0; i < c; ++i) {
    cin >> a[i];
  }
  if (c == 0 || a[c - 1] < n) {
    a.push_back(n + 1);
  }
  int ans = c;
  int pr = 0;
  for (auto t : a) {
    ans += (t - pr - 1) / k;
    pr = t;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
