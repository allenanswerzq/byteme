/* created   : 2020-03-16 22:49:18
 * accepted  : 2020-03-16 23:25:00
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
  int n; cin >> n;
  vector<int> head;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int l, r; cin >> l >> r;
    if ((l == 0 && r) || (!l && !r)) {
      head.push_back(i);
    }
    a[i] = {l, r};
  }
  vector<int> order;
  trace(head, a);
  for (int i = 0; i < (int) head.size(); i++) {
    int cur = head[i];
    while (cur != 0) {
      order.push_back(cur);
      cur = a[cur].y;
    }
  }
  trace(order);
  vector<pair<int, int>> ans(n + 1);
  for (int i = 0; i < n; i++) {
    int l = (i == 0 ? 0 : order[i - 1]);
    int r = (i == n - 1 ? 0 : order[i + 1]);
    ans[order[i]] = {l, r};
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i].x << ' ' << ans[i].y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
