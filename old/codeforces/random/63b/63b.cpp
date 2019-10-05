//=============================================================
// Name        : 63b
// Date        : Mon Jun  3 21:14:00 CST 2019
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
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a.push_back(120);
  n++;
  int ret = 0;
  while (1) {
    vi b;
    int pr = a[0];
    for (int i = 1; i < n; ++i) {
      if (a[i] != pr) {
        b.push_back(i - 1);
        pr = a[i];
      }
    }
    trace(a, b);
    bool ok = 0;
    for (auto p : b) {
      if (a[p] < k) {
        ok = 1;
        a[p]++;
      }
    }
    if (!ok) {
      break;
    }
    ret++;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
