//=============================================================
// Name        : 285b
// Date        : Thu Jun  6 20:37:59 CST 2019
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
  int n, s, t;
  cin >> n >> s >> t;
  if (s == t) {
    cout << 0 << "\n";
    return;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> was(n + 1);
  int cur = s, ans = 0;
  while (!was[cur]) {
    ans++;
    was[cur] = 1;
    cur = a[cur - 1];
    if (cur == t) {
      break;
    }
  }
  cout << (cur == t ? ans : -1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
