//=============================================================
// Name        : 195b
// Date        : Tue Jul  2 11:32:52 CST 2019
// Accepted    : Tue Jul  2 16:45:30 CST 2019
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
  int n, m;
  cin >> n >> m;
  vector<int> v;
  int md = (m + 1) / 2;
  if (m % 2 == 1) {
    v.push_back(md);
    for (int i = 1; i < md; ++i) {
      v.push_back(md - i);
      v.push_back(md + i);
    }
  }
  else {
    int lo = md, hi = md + 1;
    for (int i = 0; i < md; ++i) {
      v.push_back(lo--);
      v.push_back(hi++);
    }
  }
  trace(v);
  for (int i = 0; i < n; ++i) {
    cout << v[i % m] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
