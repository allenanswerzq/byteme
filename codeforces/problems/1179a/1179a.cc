/* created   : 2019-10-07 19:01:47
 * accepted  : 2019-10-08 23:55:06
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
  int n, q; cin >> n >> q;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    dq.push_back(a[i]);
  }
  vector<pair<int, int>> v;
  int cnt = -1;
  for (int i = 0; i < n; i++) {
    int x = dq.front(); dq.pop_front();
    int y = dq.front(); dq.pop_front();
    v.emplace_back(x, y);
    if (x <= y) {
      swap(x, y);
    }
    dq.push_front(x);
    dq.push_back(y);
    if (x == mx) {
      cnt = i + 1;
      break;
    }
  }
  trace(dq, cnt);
  for (int i = 0; i < q; i++) {
    ll x; cin >> x;
    if (x <= cnt) {
      cout << v[x - 1].x << ' ' << v[x - 1].y << '\n';
    }
    else {
      int p = (x - (cnt + 1)) % (n - 1) + 1;
      assert(1 <= p && p < n);
      trace(x, cnt, p);
      cout << mx << ' ' << dq[p] << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
