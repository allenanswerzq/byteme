/* created   : 2019-08-18 20:18:46
 * accepted  : 2019-08-18 20:31:56
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i].x >> b[i].y;
  }
  sort(b.begin(), b.end());
  trace(a, b);
  vector<ll> pr(m + 1);
  for (int i = 0; i < m; i++) {
    pr[i + 1] = pr[i] + b[i].y;
  }
  trace(pr);
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(b.begin(), b.end(), make_pair(a[i], 1 << 30));
    int p = it - b.begin();
    if (i > 0) {
      cout << ' ';
    }
    cout << pr[p] - pr[0];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
