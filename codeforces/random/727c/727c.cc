/* created   : 2019-08-16 14:26:27
 * accepted  : 2019-08-16 15:16:42
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

int send(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int ret;
  cin >> ret;
  return ret;
}

void solve() {
  int n;
  cin >> n;
  int x = send(1, 2);
  int y = send(2, 3);
  int z = send(1, 3);
  vector<int> a(n + 1);
  a[1] = ((x - y) + z) / 2;
  a[2] = x - a[1];
  a[3] = z - a[1];
  for (int i = 4; i <= n; i++) {
    int t = send(1, i);
    a[i] = t - a[1];
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
