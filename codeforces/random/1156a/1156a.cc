/*
 * created   : 2019-07-23 23:27:48
 * accepted  : 2019-07-23 23:34:51
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
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
  for (int i = 0; i < n - 1; ++i) {
    if ((a[i] == 2 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 2)) {
      cout << "Infinite" << "\n";
      return;
    }
    if (abs(a[i] - a[i + 1]) == 1) {
      ans += 3;
    }
    else {
      ans += 4;
    }
    if (i - 1 >= 0 && a[i - 1] == 3 && a[i] == 1 && a[i + 1] == 2) {
      ans--;
    }
  }
  cout << "Finite" << "\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
