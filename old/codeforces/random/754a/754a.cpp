//=============================================================
// Name        : 754a
// Date        : Wed Jun 12 20:57:00 CST 2019
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
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum != 0) {
    cout << "YES" << "\n";
    cout << 1 << "\n";
    cout << 1 << " " << n << "\n";
    return;
  }
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (sum != 0) {
      cout << "YES" << "\n";
      cout << 2 << "\n";
      cout << 1 << " " << i + 1 << "\n";
      cout << i + 2 << " " << n << "\n";
      return;
    }
  }
  cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
