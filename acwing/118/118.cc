/* created   : 2020-05-29 23:05:20
 * accepted  : 2020-05-30 10:59:33
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

int mask[4][4];

int get(int x, int y) { return x * 4 + y; }

void solve() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int val = 0;
      for (int k = 0; k < 4; k++) {
        val |= 1 << get(i, k);
        val |= 1 << get(k, j);
      }
      trace(i, j, val);
      mask[i][j] = val;
    }
  }
  int state = 0;
  for (int i = 0; i < 4; i++) {
    string x; cin >> x;
    for (int j = 0; j < 4; j++) {
      if (x[j] == '+') {
        state |= 1 << get(i, j);
      }
    }
  }
  vector<pii> ans;
  for (int k = 0; k < (1 << 16); k++) {
    vector<pii> path;
    int cur = state;
    for (int i = 0; i < 16; i++) {
      if (k >> i & 1) {
        int x = i / 4, y = i % 4;
        cur ^= mask[x][y];
        path.push_back({x, y});
      }
    }
    if (!cur && (ans.empty() || ans.size() > path.size())) {
      ans = path;
    }
  }
  cout << ans.size() << "\n";
  for (auto [x, y] : ans) {
    cout << x + 1 << " " << y + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
