//=============================================================
// Name        : 177b2
// Date        : Tue Jun  4 18:52:58 CST 2019
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
typedef vector<int> vi;

void solve() {
  int n;
  cin >> n;
  ll ret = n;
  while (1) {
    trace(n);
    bool ok = 0;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        ok = 1;
        ret += n / i;
        n = n / i;
        break;
      }
    }
    if (!ok) {
      ret++;
      break;
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
