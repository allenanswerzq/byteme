/* created   : 2020-08-24 16:43:22
 * accepted  : 2020-08-25 23:36:24
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

// TODO(): Wrong answer

void solve() {
  int n; cin >> n;
  vector<int> E(n);
  vector<int> R(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> E[i] >> R[i];
    sum += E[i];
  }
  ll max_time = sum;
  ll cur_time = sum;
  int best_remove = 0;
  int cnt = 0;
  priority_queue<pair<ll, int>> qu;
  for (int i = 0; i < n; i++) {
    if (E[i] + R[i] > sum) {
      cnt++;
      sum -= E[i];
      cur_time -= E[i];
      while (qu.size() && qu.top().first > sum) {
        int enjoy = E[qu.top().second]; qu.pop();
        sum -= enjoy;
        cur_time -= enjoy;
        cnt++;
      }
      trace(sum, i, E[i], R[i], cnt, cur_time, max_time);
    }
    else {
      qu.push({E[i] + R[i], i});
      cur_time += E[i];
    }
    trace(i, cur_time, max_time, cnt);
    if (cur_time > max_time) {
      max_time = cur_time;
      best_remove = cnt;
    }
  }
  trace(qu);
  if (qu.size()) {
    cout << cnt << " " << "INDEFINITELY\n";
  }
  else {
    cout << best_remove << " " << max_time << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
