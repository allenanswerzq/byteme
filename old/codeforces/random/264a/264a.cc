/*
 * creat   : 2019-07-16 06:22:36
 * accept  : 2019-07-16 06:25:06
 * author  : landcold7
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
  string a;
  cin >> a;
  vector<int> l, r;
  for (int i = 0; i < sz(a); ++i) {
    if (a[i] == 'l') {
      l.push_back(i);
    }
    else {
      r.push_back(i);
    }
  }
  reverse(l.begin(), l.end());
  r.insert(r.end(), l.begin(), l.end());
  for (auto x : r) {
    cout << x + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
