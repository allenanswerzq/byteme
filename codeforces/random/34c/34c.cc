/* created   : 2019-08-16 20:09:08
 * accepted  : 2019-08-16 20:20:57
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
  string s;
  cin >> s;
  s += ',';
  istringstream iss(s);
  int x;
  char c;
  vector<int> a;
  while (iss >> x >> c) {
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  trace(a);
  vector<int> cnt(1200);
  for (int i = 0; i < (int) a.size(); i++) {
    if (cnt[a[i] - 1]) {
      cnt[a[i]] = cnt[a[i] - 1] + 1;
      cnt[a[i] - 1] = 0;
    }
    else {
      cnt[a[i]] = 1;
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i < 1200; i++) {
    if (cnt[i] > 1) {
      ans.emplace_back(i - cnt[i] + 1, i);
    }
    else if (cnt[i] == 1) {
      ans.emplace_back(i, -1);
    }
  }
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << ",";
    }
    if (ans[i].y == -1) {
      cout << ans[i].x;
    }
    else {
      cout << ans[i].x << "-" << ans[i].y;
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
