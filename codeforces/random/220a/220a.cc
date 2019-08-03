/*
 * creat   : 2019-07-15 17:18:30
 * accept  : 2019-07-15 17:19:47
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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b = a;
  sort(a.begin(), a.end());
  int x = 0;
  for (int i = 0; i < n; ++i) {
    x += (a[i] != b[i]);
  }
  cout << ((x == 2 || x == 0) ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
