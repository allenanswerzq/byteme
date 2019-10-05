/*
 * created   : 2019-08-04 23:56:25
 * accepted  : 2019-08-04 23:58:17
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  iota(b.begin(), b.end(), 0);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] + 1 != a[i]) {
      cnt++;
    }
  }
  cout << ((cnt == 0 || cnt == 2) ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
