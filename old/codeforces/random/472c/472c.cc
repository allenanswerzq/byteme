/*
 * creat   : 2019-07-19 14:41:56
 * accept  : 2019-07-19 14:51:36
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<pair<string, int>> a;
  for (int i = 0; i < n; ++i) {
    string x, y;
    cin >> x >> y;
    a.emplace_back(x, i);
    a.emplace_back(y, i);
  }
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
  }
  sort(a.begin(), a.end());
  trace(a, p);
  int lo = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (a[i].y == p[lo]) {
      if (++lo == n) {
        break;
      }
    }
  }
  trace(lo, n);
  cout << (lo == n ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
