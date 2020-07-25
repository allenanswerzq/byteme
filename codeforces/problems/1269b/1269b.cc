/* created   : 2020-02-07 16:14:26
 * accepted  : 2020-02-07 16:26:35
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
#endif
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(all(b));
  vector<int> cand(n);
  for (int i = 0; i < n; i++) {
    cand[i] = (b[0] - a[i] + m) % m;
  }
  trace(cand);
  int ans = 1e9 + 7;
  for (int i = 0; i < n; i++) {
    int x = cand[i];
    vector<int> c = a;
    for (int j = 0; j < n; j++) {
      c[j] = (a[j] + x) % m;
    }
    sort(all(c));
    if (b == c) {
      ans = min(ans, x);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
