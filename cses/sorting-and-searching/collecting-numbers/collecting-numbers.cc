/* created   : 2021-02-11 08:24:18
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  priority_queue<pair<int, int>> qu;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    qu.push({-x, i});
  }
  trace(qu);
  pair<int, int> cur = {1, -1};
  int ans = 1;
  while (qu.size()) {
    auto t = qu.top();
    assert(-t.first == cur.first);
    if (t.second > cur.second) {
      qu.pop();
      cur = {-t.first + 1, t.second};
    }
    else {
      ans++;
      cur.second = -1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
