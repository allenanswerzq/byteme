/* created   : 2020-02-08 17:29:04
 * accepted  : 2020-02-08 19:45:00
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
#endif
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> costs(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> costs[i];
  }
  priority_queue<
    pair<int, int>
    // vector<pair<int, int>>,
    // greater<pair<int, int>>
  > dq;
  for (int i = 1; i <= k; i++) {
    dq.push({costs[i], i});
  }
  vector<int> ans(n + 1);
  ll sum = 0;
  for (int depart_time = k + 1; depart_time <= k + n; depart_time++) {
    if (depart_time <= n) {
      dq.push({costs[depart_time], depart_time});
    }
    ll time = dq.top().y;
    ll cost = dq.top().x;
    dq.pop();
    trace(time, depart_time, cost, dq);
    ans[time] = depart_time;
    sum += (depart_time - time) * cost;
  }
  cout << sum << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
