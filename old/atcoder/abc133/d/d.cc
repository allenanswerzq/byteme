/*
 * Name        : d
 * Creat       : Fri Jul 12 10:29:59 CST 2019
 * Accept      : Fri Jul 12 10:36:16 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
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
  vector<ll> ans(n);
  ll x = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i % 2 == 0) {
      x += a[i];
    }
    else {
      x -= a[i];
    }
  }
  trace(x);
  ans[0] = x;
  for (int i = 1; i < n; ++i) {
    ans[i] = 2 * a[i - 1] - ans[i - 1];
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
