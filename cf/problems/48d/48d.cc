/* created   : 2020-03-30 21:04:43
 * accepted  : 2020-03-30 21:21:34
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  vector<pair<int, int>> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    mp[a[i].x]++;
    a[i].y = i;
    mx = max(mx, a[i].x);
  }
  for (int i = 1; i + 1 <= mx; i++) {
    if (!mp.count(i) || !mp.count(i + 1) || mp[i] < mp[i + 1]) {
      cout << -1 << '\n';
      return;
    }
  }
  sort(all(a));
  int cur = a[0].x;
  int g = 1;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (a[i].x != cur) {
      g = 1;
      cur = a[i].x;
    }
    assert(g <= mp[1]);
    ans[a[i].y] = g++;
  }
  cout << mp[1] << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
