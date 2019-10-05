//=============================================================
// Name        : 1003b
// Date        : Thu Jun 13 11:30:24 CST 2019
// Accepted    : Thu Jun 13 14:08:49 CST 2019
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

void solve() {
  int a, b, x;
  cin >> a >> b >> x;
  int flip = 0;
  if (a < b) {
    flip = 1;
  }
  vector<int> ans;
  for (int i = 0; i <= x; ++i) {
    int v = (i + flip) % 2;
    ans.push_back(v);
    if (v == 0) {
      a--;
    } else {
      b--;
    }
  }
  trace(ans);
  while (a-- > 0) {
    trace(a);
    auto it = find(ans.begin(), ans.end(), 0);
    ans.insert(it, 0);
  }
  while (b-- > 0) {
    trace(b);
    auto it = find(ans.begin(), ans.end(), 1);
    ans.insert(it, 1);
  }
  for (auto t : ans) {
    cout << t;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
