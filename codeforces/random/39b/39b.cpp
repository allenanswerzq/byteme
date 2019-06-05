//=============================================================
// Name        : 39b
// Date        : Tue Jun  4 19:08:12 CST 2019
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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(a.begin(), a.end());
  trace(a);
  int s = 1;
  vector<int> b(1, -1);
  for (int i = 0; i < n; ++i) {
    if (a[i].x == s && a[i].y > b.back()) {
      b.push_back(a[i].y);
      s++;
    }
  }
  cout << sz(b) - 1 << "\n";
  for (int i = 1; i < sz(b); ++i) {
    cout << (2001 + b[i]) << (i == sz(b) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
