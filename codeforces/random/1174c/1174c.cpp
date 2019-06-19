//=============================================================
// Name        : 1174c
// Date        : Wed Jun 12 20:29:20 CST 2019
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
  vector<int> a(n + 1);
  int k = 0;
  for (int i = 2; i <= n; ++i) {
    if (!a[i]) {
      a[i] = ++k;
      for (int j = i; j < n; j += i) {
        a[i] = k;
      }
    }
  }
  trace(a);
  for (int i = 2; i <= n; ++i) {
    cout << a[i] << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
