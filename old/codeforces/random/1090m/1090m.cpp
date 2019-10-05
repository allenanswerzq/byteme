//=============================================================
// Name        : 1090m
// Date        : Mon Jun  3 09:35:14 CST 2019
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
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  trace(a);
  int lo = -1, ret = 0;
  for (int i = 0; i < n; ++i) {
    while (i + 1 < n && a[i] != a[i + 1]) {
      i++;
    }
    ret = max(ret, i - lo);
    lo = i;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
