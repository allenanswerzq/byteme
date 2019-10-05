//=============================================================
// Name        : 814b
// Date        : Wed Jun 26 10:53:36 CST 2019
// Accepted    : Wed Jun 26 11:40:37 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> ans(n);
  bitset<1200> bs;
  vector<int> p;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      ans[i] = a[i];
      bs.set(a[i]);
    } else {
      p.push_back(i);
    }
  }
  vector<int> miss;
  for (int i = 1; i <= n; ++i) {
    if (bs.test(i) == 0) {
      miss.push_back(i);
    }
  }
  auto check = [&]() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += (ans[i] != a[i]);
    }
    if (cnt != 1) {
      return 0;
    }
    for (int i = 0; i < n; ++i) {
      cnt += (ans[i] != b[i]);
    }
    if (cnt != 2) {
      return 0;
    }
    return 1;
  };
  trace(ans, miss, p);
  if (sz(p) == 1) {
    ans[p[0]] = miss[0];
  } else if (sz(p) == 2) {
    for (int i = 0; i < 2; ++i) {
      ans[p[i]] = miss[i];
    }
    if (!check()) {
      for (int i = 0; i < 2; ++i) {
        ans[p[i]] = miss[1 - i];
      }
    }
  } else {
    assert(0);
  }
  trace(ans, bs);
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
