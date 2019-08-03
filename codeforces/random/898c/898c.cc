/*
 * created   : 2019-08-02 11:50:50
 * accepted  : 2019-08-02 12:44:46
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
  int n;
  cin >> n;
  map<string, vector<string>> mp;
  for (int i = 0; i < n; i++) {
    string name;
    int k;
    cin >> name >> k;
    for (int j = 0; j < k; j++) {
      string x;
      cin >> x;
      mp[name].push_back(x);
    }
  }
  trace(mp);
  map<string, set<string>> ans;
  for (auto it : mp) {
    auto v = it.y;
    int nv = (int) v.size();
    for (int i = 0; i < nv; i++) {
      bool ok = 0;
      for (int j = 0; j < nv; j++) {
        int ni = v[i].size();
        int nj = v[j].size();
        if (nj >= ni && v[j] != v[i] && v[j].substr(nj - ni) == v[i]) {
          ok = 1;
          break;
        }
      }
      if (!ok && !ans[it.x].count(v[i])) {
        ans[it.x].insert(v[i]);
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto it : ans) {
    cout << it.x << " ";
    vector<string> v(ans[it.x].begin(), ans[it.x].end());
    int na = v.size();
    cout << na << " ";
    for (int i = 0; i < na; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << v[i];
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
