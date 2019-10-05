/*
 * created   : 2019-07-28 22:33:46
 * accepted  : 2019-07-28 23:17:15
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
  int n, s;
  cin >> n >> s;
  map<int, ll, greater<int>> buy;
  map<int, ll> sell;
  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++) {
    char x;
    int p, d;
    cin >> x >> p >> d;
    a[i] = {x, p};
    if (x == 'B') {
      buy[p] += d;
    }
    else {
      sell[p] += d;
    }
  }
  trace(buy, sell, n);
  vector<pair<int, int>> ans;
  int k = 0;
  for (auto it : sell) {
    if (k++ >= s) {
      break;
    }
    ans.emplace_back(it.x, it.y);
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << "S " << ans[i].x << " " << ans[i].y << "\n";
  }
  k = 0;
  for (auto it : buy) {
    if (k++ >= s) {
      break;
    }
    cout << "B " << it.x << " " << it.y << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
