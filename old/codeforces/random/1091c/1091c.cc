/*
 * Creat   : Mon Jul 15 10:51:22 CST 2019
 * Accept  : Mon Jul 15 12:00:30 CST 2019
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
  vector<ll> ans;
  auto go = [&](int g) {
    int x = n / g;
    int fr = 1;
    int lt = fr + (x - 1) * g;
    ans.push_back((ll) (fr + lt) * x / 2);
  };
  for (int g = 1; g * g <= n; ++g) {
    if (n % g == 0) {
      go(g);
      go(n / g);
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  for (int i = 0; i < sz(ans); ++i) {
    cout << ans[i] << (i == sz(ans) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
