/*
 * created   : 2019-07-23 17:49:05
 * accepted  : 2019-07-23 18:02:54
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, pair<int, int>>> a;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    vector<int> t(k);
    ll sum = 0;
    for (int j = 0; j < k; ++j) {
      cin >> t[j];
      sum += t[j];
    }
    trace(t);
    for (int j = 0; j < k; ++j) {
      a.push_back({sum - t[j], {i, j}});
    }
  }
  sort(a.begin(), a.end());
  trace(a);
  for (int i = 0; i < (int) a.size() - 1; ++i) {
    if (a[i].x == a[i + 1].x && a[i].y.x != a[i + 1].y.x) {
      cout << "YES" << "\n";
      cout << a[i].y.x + 1 << " " << a[i].y.y + 1 << "\n";
      cout << a[i + 1].y.x + 1 << " " << a[i + 1].y.y + 1 << "\n";
      return;
    }
  }
  cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
