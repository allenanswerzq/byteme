//=============================================================
// Name        : 926a
// Date        : Sat Jul  6 09:35:06 CST 2019
// Accepted    : Sat Jul  6 09:53:25 CST 2019
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

ll go(ll a) {
  ll t = 1, x = 0;
  while (t < a) {
    t *= 2;
    x++;
  }
  ll m = 1, y = 0;
  while (m < a) {
    m *= 3;
    y++;
  }
  int ans = 0;
  for (int i = x; i >= 0; --i) {
    for (int j = y; j >= 0; --j) {
      ll v = llround(pow(2, i)) * llround(pow(3, j));
      if (v <= a) {
        ans++;
      }
    }
  }
  return ans;
}

void solve() {
  int l, r;
  cin >> l >> r;
  cout << go(r) - go(l - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
