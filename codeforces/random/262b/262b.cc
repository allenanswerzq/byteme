//=============================================================
// Name        : 262b
// Date        : Wed Jun 26 15:08:37 CST 2019
// Accepted    : Wed Jun 26 16:01:53 CST 2019
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n && k > 0 && a[i] < 0; ++i) {
    a[i] *= -1;
    k--;
  }
  sort(a.begin(), a.end());
  if (k % 2 == 1) {
    a[0] *= -1;
  }
  cout << accumulate(a.begin(), a.end(), 0) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
