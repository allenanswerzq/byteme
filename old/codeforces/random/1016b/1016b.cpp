//=============================================================
// Name        : 1016b
// Date        : Tue Jun 11 13:41:48 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve_binary_search() {
  int n, m, q;
  cin >> n >> m >> q;
  string s, t;
  cin >> s >> t;
  vector<int> a;
  // O(n * m)
  for (int i = 0; i < n; ++i) {
    int len = (int) t.size();
    if (s.substr(i, len) == t) {
      a.emplace_back(i + 1);
    }
  }
  trace(a);
  // O(q * nlogn)
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    int len = (int) t.size();
    int lo = lower_bound(a.begin(), a.end(), x) - a.begin();
    int hi = upper_bound(a.begin(), a.end(), y - len + 1) - a.begin() - 1;
    trace(lo, hi);
    int ans = max(0, hi - lo + 1);
    cout << ans << "\n";
  }
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  string s, t;
  cin >> s >> t;
  vector<bool> was(n);
  vector<int> pr(n + 1);
  int len = (int) t.size();
  for (int i = 0; i < n; ++i) {
    if (s.substr(i, len) == t) {
      was[i] = 1;
    }
    pr[i + 1] = pr[i] + was[i];
  }
  trace(was, pr);
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    y = y - m + 1;
    int ans = 0;
    if (y >= x) {
      ans = pr[y] - pr[x - 1];
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
