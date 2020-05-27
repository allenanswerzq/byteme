/* created   : 2020-05-27 22:01:33
 * accepted  : 2020-05-27 22:36:12
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

void solve() {
  int n; cin >> n;
  vector<pair<pii, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x.x >> a[i].x.y;
    a[i].y = i;
  }
  sort(all(a));
  vector<int> ans(n);
  int cnt = 1;
  priority_queue<pii, vector<pii>> qi;
  ans[a[0].y] = cnt;
  qi.push({-a[0].x.y, a[0].y});
  for (int i = 1; i < n; i++) {
    int start = a[i].x.x;
    int tp = -qi.top().x;
    int id = qi.top().y;
    trace(start, tp, id, ans[id], qi);
    assert(ans[id]);
    if (tp < start) {
      qi.pop();
      ans[a[i].y] = ans[id];
      qi.push({-a[i].x.y, a[i].y});
    }
    else {
      ans[a[i].y] = ++cnt;
      qi.push({-a[i].x.y, a[i].y});
    }
  }
  cout << cnt << "\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
