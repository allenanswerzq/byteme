//=============================================================
// Name        : 567b
// Date        : Fri Jun  7 17:19:32 CST 2019
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
  int ans = 0, a = 0;
  const int maxn = 1e6 + 7;
  vector<bool> was(maxn);
  for (int i = 0; i < n; ++i) {
    char op;
    int id;
    cin >> op >> id;
    if (op == '+') {
      a++;
      was[id] = 1;
      ans = max(ans, a);
    } else {
      if (!was[id]) {
        ans++;
      } else {
        a--;
      }
      was[id] = 0;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
