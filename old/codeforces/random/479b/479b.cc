/*
 * created   : 2019-07-26 09:07:26
 * accepted  : 2019-07-26 09:23:04
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> ret;
  for (int i = 0; i < k; ++i) {
    pair<int, int> mx = {0, -1};
    pair<int, int> mi = {(1 << 30), -1};
    for (int j = 0; j < n; ++j) {
      if (a[j] > mx.x) {
        mx = {a[j], j};
      }
      if (a[j] < mi.x) {
        mi = {a[j], j};
      }
    }
    if (mx.x - mi.x == 0) {
      break;
    }
    ret.emplace_back(mx.y, mi.y);
    a[mx.y]--;
    a[mi.y]++;
  }
  int ans = *max_element(a.begin(), a.end());
  ans -= *min_element(a.begin(), a.end());
  int nz = (int) ret.size();
  cout << ans << " " << nz << "\n";
  for (int i = 0; i < nz; ++i) {
    cout << ret[i].x + 1 << " " << ret[i].y + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
