/*
 * created   : 2019-08-03 00:05:57
 * accepted  : 2019-08-03 00:16:54
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1 << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << i << (i == n - 1 ? "\n" : " ");
  }
  for (int i = 0; i < n; i++) {
    cout << i << (i == n - 1 ? "\n" : " ");
  }
  for (int i = 0; i < n; i++) {
    cout << (i + i) % n << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
