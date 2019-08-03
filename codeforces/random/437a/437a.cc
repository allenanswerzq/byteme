/*
 * creat   : 2019-07-17 09:12:31
 * accept  : 2019-07-17 09:21:58
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
  vector<int> a(4);
  for (int i = 0; i < 4; ++i) {
    string s;
    cin >> s;
    a[i] = sz(s) - 2;
  }
  trace(a);
  vector<int> b;
  for (int i = 0; i < 4; ++i) {
    int x = 0;
    int y = 0;
    for (int j = 0; j < 4; ++j) {
      if (a[i] * 2 <= a[j]) {
        x++;
      }
      if (a[i] >= a[j] * 2) {
        y++;
      }
    }
    if (x == 3 || y == 3) {
      b.push_back(i);
    }
  }
  trace(b);
  cout << (sz(b) == 1 ? (char)('A' + b[0]) : 'C') << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
