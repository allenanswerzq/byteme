/*
 * creat   : 2019-07-20 09:02:26
 * accept  : 2019-07-20 09:16:56
 * author  : landcold7
 */
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(a.begin(), a.end());
  trace(a);
  cout << a[(n - 1) / 2].x << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
