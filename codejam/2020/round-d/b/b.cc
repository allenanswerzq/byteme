/* created   : 2020-07-12 13:15:43
 * accepted  : 2020-07-12 15:17:04
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  vector<int> d;
  d.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    if (a[i] != d.back()) {
      d.push_back(a[i]);
    }
  }
  trace(d);
  int ans = 1e9 + 7;
  for (int k = 0; k < 3; k++) {
    int cnt = 0;
    int s = k;
    for (int i = 0; i + 1 < d.size(); i++) {
      s += (d[i + 1] > d[i] ? 1 : -1);
      if (s > 3) {
        cnt++, s = 0;
      }
      else if (s < 0) {
        cnt++, s = 2;
      }
    }
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
