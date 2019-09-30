/* created   : 2019-09-10 23:53:52
 * accepted  : 2019-09-11 00:05:12
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> va, vb;
  ll sa = 0;
  ll sb = 0;
  int last = -1;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x > 0) {
      sa += x;
      va.push_back(x);
      last = 0;
    }
    else {
      sb += -x;
      vb.push_back(-x);
      last = 1;
    }
  }
  trace(sa, sb, va, vb);
  bool ans = 0;
  if (sa > sb) {
    ans = 0;
  }
  else if (sa < sb) {
    ans = 1;
  }
  else if (va > vb) {
    ans = 0;
  }
  else if (va < vb) {
    ans = 1;
  }
  else if (last == 0) {
    ans = 0;
  }
  else {
    ans = 1;
  }
  cout << (ans ? "second\n" : "first\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
