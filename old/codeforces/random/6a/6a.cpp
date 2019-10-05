//=============================================================
// Name        : 6a
// Date        : Wed Jun  5 14:53:01 CST 2019
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
  vector<int> a(4);
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }
  bool ok = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      for (int k = j + 1; k < 4; ++k) {
        vector<int> b = {a[i], a[j], a[k]};
        sort(b.begin(), b.end());
        if (b[0] + b[1] > b[2] && abs(b[0] - b[1]) < b[2]) {
          cout << "TRIANGLE\n";
          return;
        } else if (b[0] + b[1] == b[2]) {
          ok = 1;
        }
      }
    }
  }
  cout << (ok ? "SEGMENT\n" : "IMPOSSIBLE\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
