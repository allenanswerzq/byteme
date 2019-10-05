/*
 * created   : 2019-07-31 19:46:38
 * accepted  : 2019-07-31 19:49:36
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
  string a, b;
  cin >> a >> b;
  if (a.size() == 1) {
    cout << (a == b ? "OK" : "WRONG_ANSWER") << "\n";
    return;
  }
  sort(a.begin(), a.end());
  if (a[0] == '0') {
    swap(a[0], a[1]);
  }
  cout << (a == b ? "OK" : "WRONG_ANSWER") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
