/* created   : 2020-05-11 23:07:27
 * accepted  : 2020-05-11 23:50:44
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s; cin >> s;
  vector<vector<int>> ans;
  set<int> one;
  set<int> zero;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '0') {
      if (one.empty()) {
        ans.push_back({i});
        zero.insert(ans.size() - 1);
      }
      else {
        int id = *one.begin();
        one.erase(id);
        ans[id].push_back(i);
        zero.insert(id);
      }
    }
    else {
      if (zero.empty()) {
        cout << -1 << "\n";
        return;
      }
      else {
        int id = *zero.begin();
        zero.erase(id);
        ans[id].push_back(i);
        one.insert(id);
      }
    }
  }
  if (!one.empty()) {
    cout << -1 << "\n";
    return;
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].size() << " ";
    for (int j = 0; j < (int) ans[i].size(); j++) {
      if (j > 0) {
        cout << " ";
      }
      cout << ans[i][j] + 1;
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
