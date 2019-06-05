//=============================================================
// Name        : 169b
// Date        : Tue Jun  4 15:43:14 CST 2019
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
  string a, b;
  cin >> a >> b;
  sort(b.begin(), b.end());
  for (int i = 0; i < sz(a); ++i) {
    if (sz(b) && a[i] < b.back()) {
      a[i] = b.back();
      b.pop_back();
    }
  }
  cout << a << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
