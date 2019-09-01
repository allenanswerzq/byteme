/* created   : 2019-09-01 11:10:48
 * accepted  : 2019-09-01 23:17:16
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
  int n; cin >> n;
  vector<int> a(n);
  vector<ll> pr(n + 1);
  vector<pair<ll, int>> ng(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pr[i + 1] = pr[i] + a[i];
    ng[i + 1].x = ng[i].x + (a[i] < 0 ? a[i] : 0);
    ng[i + 1].y = ng[i].y + (a[i] < 0);
  }
  map<int, pair<int, int>> pos;
  for (int i = 0; i < n; i++) {
    int v = a[i];
    if (pos.count(v)) {
      pos[v].y = i;
    }
    else {
      pos[v] = {i, -1};
    }
  }
  ll ans = -1e18;
  pair<int, int> best;
  for (auto it : pos) {
    int x = it.y.x;
    int y = it.y.y;
    if (x != -1 && y != -1 && x < y) {
      ll cur = pr[y + 1] - pr[x];
      ll neg = ng[y].x - ng[x + 1].x;
      trace(x, y, ans, cur, neg);
      if (ans <= cur - neg) {
        ans = cur - neg;
        best = it.y;
      }
    }
  }
  int discard = (n - best.y - 1) + best.x + ng[best.y].y - ng[best.x + 1].y;
  cout << ans << ' ' << discard << '\n';
  vector<int> v;
  int cnt = discard;
  trace(pr, ng, ans, best, discard);
  for (int i = 0; i < n && cnt; i++) {
    if (i < best.x) {
      v.push_back(i);
      cnt--;
    }
    else if (i > best.y) {
      v.push_back(i);
      cnt--;
    }
    else if (best.x < i && i < best.y && a[i] < 0) {
      v.push_back(i);
      cnt--;
    }
  }
  int nv = v.size();
  for (int i = 0; i < (int) v.size(); i++) {
    cout << v[i] + 1 << (i == nv - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
