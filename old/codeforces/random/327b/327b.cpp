//=============================================================
// Name        : 327b
// Date        : Wed Jun  5 16:38:11 CST 2019
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
  const int inf = 1e7;
  vector<bool> was(inf + 1);
  vector<int> ret;
  for (int i = 2; i <= inf && sz(ret) < n; ++i) {
    if (!was[i]) {
      ret.push_back(i);
      for (int j = i; j <= inf; j += i) {
        was[j] = 1;
      }
    }
  }
  assert(sz(ret) == n);
  for (int i = 0; i < sz(ret); ++i) {
    cout << ret[i] << (i == sz(ret) - 1 ? "\n": " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
