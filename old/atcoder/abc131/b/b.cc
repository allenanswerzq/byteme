/*
 * Name        : b
 * Creat       : Fri Jul 12 17:52:09 CST 2019
 * Accept      : Fri Jul 12 17:57:36 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
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
  int n, l;
  cin >> n >> l;
  vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = l + i - 1;
    sum += a[i];
  }
  trace(a);
  int mi = (1 << 30);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int d = abs(sum - a[i] - sum);
    if (d < mi) {
      mi = d;
      ans = sum - a[i];
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
