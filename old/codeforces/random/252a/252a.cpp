//=============================================================
// Name        : 252a
// Date        : Sun Jun  2 11:40:19 CST 2019
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
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int tmp = 0;
      for (int k = i; k <=j; ++k) {
        tmp ^= a[k];
      }
      ret = max(ret, tmp);
    }
  }
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
