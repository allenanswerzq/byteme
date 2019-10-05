/* created   : 2019-08-17 16:10:59
 * accepted  : 2019-08-17 16:32:36
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
  vector<int> a(n), b(n);
  bool x = 0;
  bool y = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      x = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] == 0) {
      y = 1;
    }
  }
  if (!x) {
    cout << (a == b ? "YES" : "NO") << '\n';
    return;
  }
  else if (x && !y) {
    cout << "NO" << '\n';
    return;
  }
  a.erase(find(a.begin(), a.end(), 0));
  b.erase(find(b.begin(), b.end(), 0));
  trace(a, b);
  int p = -1;
  for (int i = 0; i < n - 1; i++) {
    if (b[i] == a[0]) {
      p = i;
      break;
    }
  }
  assert(p != -1);
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != b[p]) {
      cout << "NO" << '\n';
      return;
    }
    p = (p + 1) % (n - 1);
  }
  cout << "YES" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
