//=============================================================
// Name        : 794b
// Date        : Fri Jun 28 15:32:22 CST 2019
// Accepted    : Fri Jun 28 15:46:22 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, h;
  cin >> n >> h;
  double area = 1.0 * h / n;
  double ratio = 1.0 / h;
  for (int i = 1; i <= n - 1; ++i) {
    double h1 = sqrt(i * area / ratio);
    cout << h1 << (i == n - 1 ? "\n": " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(20) << "\n";
  solve();
  return 0;
}
