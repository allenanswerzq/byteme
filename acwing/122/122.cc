/* created   : 2020-05-31 09:55:02
 * accepted  : 2020-05-31 11:16:26
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

ll prefix_sum(vector<array<int, 3>>& a, int md) {
  ll ps = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    int s = a[i][0];
    int e = a[i][1];
    int d = a[i][2];
    if (s <= md) {
      int x = min(md, e) - s;
      assert(d > 0);
      ps += max(x, 0) / d + 1;
    }
  }
  return ps;
}

void solve() {
  int n; cin >> n;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  const int INF = 1e9;
  int lo = -1;
  int hi = INF;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    if (prefix_sum(a, md) % 2 == 0) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  if (hi == INF) {
    cout << "There's no weakness.\n";
  }
  else {
    cout << hi << " " << prefix_sum(a, hi) - prefix_sum(a, hi - 1) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
