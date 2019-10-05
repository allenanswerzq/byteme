/*
 * created   : 2019-08-04 23:02:07
 * accepted  : 2019-08-04 23:08:03
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
  int n, d;
  cin >> n >> d;
  int a, b;
  cin >> a >> b;
  vector<pair<ll, int>> v(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i].x = x * a + y * b;
    v[i].y = i;
  }
  sort(v.begin(), v.end());
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (d >= v[i].x) {
      ans.push_back(v[i].y);
      d -= v[i].x;
    }
  }
  int na = ans.size();
  cout << na << "\n";
  for (int i = 0; i < na; i++) {
    cout << ans[i] + 1 << (i == na - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
