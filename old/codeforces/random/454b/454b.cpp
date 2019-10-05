//=============================================================
// Name        : 454b
// Date        : Wed Jun  5 11:33:56 CST 2019
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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int i = 0;
  while (i + 1 < n && a[i + 1] >= a[i]) {
    i++;
  }
  int bk = i;
  i++;
  while (i + 1 < n && a[i + 1] >= a[i]) {
    i++;
  }
  if (i < n - 1 || (n > 2 && a[0] < a[n - 1])) {
    cout << -1 << "\n";
  } else {
    cout << (n - bk - 1) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
