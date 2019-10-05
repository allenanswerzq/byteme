//=============================================================
// Name        : 47b
// Date        : Sun Jun  2 18:59:05 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  vector<vector<int>> a(3);
  for (int i = 0; i < 3; ++i) {
    string x;
    cin >> x;
    if (x[1] == '>') {
      a[x[0] - 'A'].push_back(x[2] - 'A');
    } else {
      a[x[2] - 'A'].push_back(x[0] - 'A');
    }
  }
  if (sz(a[0]) && sz(a[1]) && sz(a[2])) {
    cout << "Impossible\n";
    return;
  }
  for (int k = 0; k < 3; ++k) {
    for (int i = 0; i < 3; ++i) {
      if (sz(a[i]) == k) {
        cout << char(i + 'A');
      }
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
