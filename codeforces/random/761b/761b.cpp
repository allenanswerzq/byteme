//=============================================================
// Name        : 761b
// Date        : Fri Jun 14 15:28:26 CST 2019
// Accepted    : Fri Jun 14 15:54:31 CST 2019
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    int start = i;
    vector<int> d;
    for (int j = 0; sz(d) < n; ++j) {
      d.push_back((a[j] - start + m) % m);
    }
    sort(d.begin(), d.end());
    trace(start, a, d);
    if (d == b) {
      cout << "YES" << "\n";
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
