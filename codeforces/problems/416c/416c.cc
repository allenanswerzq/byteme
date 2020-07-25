/* created   : 2020-05-05 21:21:30
 * accepted  : 2020-05-05 21:41:30
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

bool comp(array<int, 3>& a, array<int, 3>& b) {
  if (a[0] != b[0]) {
    return a[0] > b[0];
  }
  else {
    return a[1] < b[1];
  }
}

void solve() {
  int n; cin >> n;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    int c, p; cin >> c >> p;
    a[i] = {p, c, i};
  }
  sort(all(a), comp);
  int m; cin >> m;
  set<pair<int, int>> st;
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    st.insert({x, i});
  }
  trace(a, st);
  vector<pair<int, int>> ans;
  int money = 0;
  for (int i = 0; i < n; i++) {
    auto it = st.lower_bound({a[i][1], -1});
    if (it != st.end()) {
      money += a[i][0];
      ans.push_back({a[i][2], it->y});
      st.erase(it);
    }
  }
  int na = ans.size();
  cout << na << " " << money << "\n";
  for (int i = 0; i < na; i++) {
    cout << ans[i].x + 1 << " " << ans[i].y + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
