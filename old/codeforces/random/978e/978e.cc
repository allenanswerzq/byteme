/*
 * created   : 2019-07-28 09:37:26
 * accepted  : 2019-07-28 09:44:34
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
  vector<int> pr(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pr[i + 1] = pr[i] + x;
  }
  int mx = *max_element(pr.begin(), pr.end());
  int mi = *min_element(pr.begin(), pr.end());
  trace(mx, mi);
  // -mi <= x && x <= m - mx
  cout << max(0, m - mx + mi +1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
