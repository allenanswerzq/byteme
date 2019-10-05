//=============================================================
// Name        : 1037c
// Date        : Wed Jun  5 17:36:58 CST 2019
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
  string a, b;
  cin >> a >> b;
  vector<int> ne;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      ne.push_back(i);
    }
  }
  trace(ne);
  int ret = 0;
  for (int i = 0; i < sz(ne); ++i) {
    if (i + 1 < sz(ne) && ne[i + 1] - ne[i] == 1) {
      int x = ne[i + 1], y = ne[i];
      if (a[x] == b[y] && a[y] == b[x]) {
        ret++, i++;
      } else {
        ret += 1;
      }
    } else {
      ret++;
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
