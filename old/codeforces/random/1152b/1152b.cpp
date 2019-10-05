//=============================================================
// Name        : 1152b
// Date        : Mon Jun 17 16:43:03 CST 2019
// Accepted    : Mon Jun 17 16:50:14 CST 2019
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

bool check(int x) {
  if (x && !(x & (x - 1))) {
    return true;
  }
  return false;
}

void solve() {
  int x;
  cin >> x;
  int cnt = 0;
  vector<int> ans;
  while (true) {
    trace(x);
    if (check(x + 1)) {
      break;
    }
    int t = 1, n = 0;
    while ((x + 1) > t) {
      n++;
      t <<= 1;
    }
    trace(t);
    x = x ^ (t - 1);
    cnt++;
    ans.push_back(n);
    if (check(x + 1)) {
      break;
    }
    x = x + 1;
    cnt++;
  }
  trace(cnt, x);
  assert(check(x + 1));
  cout << cnt << "\n";
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
