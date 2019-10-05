//=============================================================
// Name        : 174a
// Date        : Tue Jun  4 19:25:59 CST 2019
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
  int sum = k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  double t = sum * 1.0 / n;
  vector<double> ret;
  for (int i = 0; i < n; ++i) {
    if (t - a[i] < 0) {
      cout << -1 << "\n";
      return;
    } else {
      ret.push_back(t - a[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ret[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(6) << fixed;
  solve();
  return 0;
}
