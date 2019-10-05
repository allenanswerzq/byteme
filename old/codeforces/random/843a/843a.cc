/*
 * created   : 2019-07-30 23:50:46
 * accepted  : 2019-07-31 18:26:38
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(a.begin(), a.end());
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = a[i].y;
  }
  trace(a, p);
  vector<bool> was(n);
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }
    int x = i;
    vector<int> cycle;
    while (!was[x]) {
      was[x] = true;
      cycle.push_back(x);
      x = p[x];
    }
    ans.push_back(cycle);
  }
  cout << ans.size() << "\n";
  for (auto t : ans) {
    sort(t.begin(), t.end());
    int nt = (int) t.size();
    cout << nt << " ";
    for (int i = 0; i < nt; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << t[i] + 1;
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
