/*
 * Creat   : Sun Jul 14 17:01:33 CST 2019
 * Accept  : Sun Jul 14 17:22:51 CST 2019
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
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<ll, ll>> e;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i] * 2 == a[j]) {
        e.emplace_back(a[i], a[j]);
      }
      if (a[i] % 3 == 0 && a[i] / 3 == a[j]) {
        e.emplace_back(a[i], a[j]);
      }
    }
  }
  trace(e);
  for (int i = 0; i < n; ++i) {
    ll root = a[i];
    vector<ll> ans;
    ans.push_back(root);
    while (1) {
      bool ok = 0;
      for (int j = 0; j < sz(e); ++j) {
        if (e[j].x == root) {
          ok = 1;
          root = e[j].y;
          ans.push_back(root);
        }
      }
      if (!ok) {
        break;
      }
    }
    trace(root, ans);
    if (sz(ans) == n) {
      for (int j = 0; j < n; ++j) {
        cout << ans[j] << (j == n - 1 ? "\n" : " ");
      }
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
