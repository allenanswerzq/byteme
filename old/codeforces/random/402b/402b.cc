/* created   : 2019-08-14 23:25:04
 * accepted  : 2019-08-14 23:29:42
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> v;
  int ans = 2000;
  for (int i = 1; i <= 1000; i++) {
    vector<int> b(n);
    b[0] = i;
    for (int j = 1; j < n; j++) {
      b[j] = b[j - 1] + k;
    }
    int cur = 0;
    for (int j = 0; j < n; j++) {
      cur += (a[j] != b[j]);
    }
    if (cur < ans) {
      ans = cur;
      v = b;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    if (a[i] < v[i]) {
      cout << "+ " << i + 1 << " " << v[i] - a[i] << "\n";
    }
    else if (a[i] > v[i]) {
      cout << "- " << i + 1 << " " << a[i] - v[i] << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
