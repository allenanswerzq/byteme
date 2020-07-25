/* created   : 2020-03-16 20:56:14
 * accepted  : 2020-03-16 22:07:51
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    a[i] = x * m + y;
  }
  sort(all(a));
  trace(a);
  for (int i = 0; i < t; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    int p = lower_bound(all(a), x * m + y) - a.begin();
    trace(x, y, p);
    if (p < k && a[p] == x * m + y) {
      cout << "Waste" << '\n';
    }
    else {
      int waste = p;
      int kind = (x * m + y + 1 - waste - 1) % 3;
      trace(x, y, waste, kind);
      if (kind == 0) {
        cout << "Carrots" << '\n';
      }
      else if (kind == 1) {
        cout << "Kiwis" << '\n';
      }
      else {
        cout << "Grapes" << '\n';
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
