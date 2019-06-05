//=============================================================
// Name        : 967a
// Date        : Sun Jun  2 10:55:54 CST 2019
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
  int n, s;
  cin >> n >> s;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[i] = x * 60 + y;
  }
  const int inf = 1e9 + 7;
  a.push_back(inf);
  if (a[0] != 0) {
    a.insert(a.begin(), -inf);
  }
  trace(a);
  n = sz(a);
  int ret = -1;
  for (int i = 0; i < n - 1; ++i) {
    if (i == 0 && a[i] < 0) {
      if (1 <= a[i + 1] - s) {
        ret = 0;
        break;
      }
    } else if (a[i] + s + 2 <= a[i + 1] - s) {
      ret = a[i] + s + 1;
      break;
    }
  }
  trace(ret);
  int h = ret / 60;
  int m = ret % 60;
  cout << h << " " << m << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
