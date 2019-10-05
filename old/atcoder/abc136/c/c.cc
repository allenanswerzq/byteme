/* created   : 2019-08-11 23:15:12
 * accepted  : 2019-08-11 23:23:15
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
  int pr = -999;
  for (int i = 0; i < n; i++) {
    if (pr <= a[i] - 1) {
      a[i]--;
      pr = a[i];
    }
    else if (pr <= a[i]) {
      pr = a[i];
    }
    else {
      cout << "No" << "\n";
      return;
    }
  }
  cout << "Yes" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
