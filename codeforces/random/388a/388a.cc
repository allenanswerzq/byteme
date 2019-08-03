/*
 * Creat   : Mon Jul 15 09:28:39 CST 2019
 * Accept  : Mon Jul 15 09:53:13 CST 2019
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

void solve2() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  trace(a);
  vector<bool> use(n, false);
  int lo = 0;
  int ans = 0;
  while (lo < n) {
    ans++;
    int top = 0;
    for (int i = 0; i < n; ++i) {
      if (!use[i] && a[i] >= top) {
        top++;
        use[i] = true;
        lo++;
      }
    }
  }
  cout << ans << "\n";
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> cnt(n);
  for (auto x : a) {
    for (int i = 0; i < n; ++i) {
      if (cnt[i] <= x) {
        cnt[i]++;
        break;
      }
    }
  }
  trace(a, cnt);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] != 0) {
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
