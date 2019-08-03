/*
 * Creat   : Sun Jul 14 16:41:35 CST 2019
 * Accept  : Sun Jul 14 16:47:18 CST 2019
 * Author  : landcold7
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(a.begin(), a.end());
  vector<ll> pr(n + 1);
  for (int i = 0; i < n; ++i) {
    pr[i + 1] = pr[i] + a[i].x;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    int p = (i == n - 1 ? n - 2 : n - 1);
    ll x = pr[n] - a[i].x - a[p].x;
    if (x == a[p].x) {
      ans.push_back(a[i].y);
    }
  }
  cout << sz(ans) << "\n";
  for (int i = 0; i < sz(ans); ++i) {
    cout << ans[i] + 1 << (i == sz(ans) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
