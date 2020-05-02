/* created   : 2020-05-02 16:45:33
 * accepted  : 2020-05-02 17:02:38
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) continue;
    bool ok = false;
    for (int j = i + 1; j < n; j++) {
      if (s[j] == s[i]) {
        swap(s[j], t[i]);
        ok = true;
        ans.push_back({j, i});
        break;
      }
    }
    if (ok) continue;
    for (int j = i + 1; j < n; j++) {
      if (t[j] == s[i]) {
        swap(t[j], s[j]);
        ans.push_back({j, j});
        trace(i, j, s, t);
        swap(t[i], s[j]);
        ans.push_back({j, i});
        trace(i, j, s, t);
        ok = true;
        break;
      }
    }
    trace(i, ok);
    if (!ok) {
      cout << "No" << "\n";
      return;
    }
  }
  trace(s, t);
  cout << "Yes" << "\n";
  int m = ans.size();
  cout << m << "\n";
  for (int i = 0; i < m; i++) {
    cout << ans[i].x + 1 << " " << ans[i].y + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
