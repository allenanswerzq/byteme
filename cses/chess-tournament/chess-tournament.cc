/* created   : 2021-01-18 22:11:09 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  priority_queue<pair<int, int>> qu;
  for (int i = 1; i <= N; i++) {
    int x; cin >> x;
    if (x > 0) {
      qu.push({x, i});
    }
  }
  trace(qu);
  vector<pair<int, int>> ans;
  while (qu.size()) {
    auto to = qu.top(); qu.pop();
    if (to.first > qu.size()) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    vector<pair<int, int>> tmp;
    for (int i = 0; i < to.first; i++) {
      tmp.push_back(qu.top());
      qu.pop();
    }
    for (auto t : tmp) {
      ans.push_back({to.second, t.second});
      if (t.first > 1) {
        qu.push({t.first - 1, t.second});
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto& it : ans) {
    cout << it.first << " " << it.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
