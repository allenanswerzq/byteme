/*
 * created   : 2019-07-24 23:40:47
 * accepted  : 2019-07-24 23:40:48
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
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
  reverse(a.begin(), a.end());
  trace(a);
  for (int i = 0; i < n; ++i) {
    if (i == a[0].y) {
      cout << a[1].x << "\n";
    }
    else {
      cout << a[0].x << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
