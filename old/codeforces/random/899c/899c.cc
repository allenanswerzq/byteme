//=============================================================
// Name        : 899c
// Date        : Fri Jun 21 14:07:46 CST 2019
// Accepted    : Fri Jun 21 15:11:31 CST 2019
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
  int n;
  cin >> n;
  vector<int> a, b;
  int lo = 1, hi = n;
  if (n % 4 == 1) {
    a.push_back(lo++);
  } else if (n % 4 == 2) {
    a.push_back(lo++);
    b.push_back(lo++);
  } else if (n % 4 == 3) {
    a.push_back(lo++);
    a.push_back(lo++);
    b.push_back(lo++);
  }
  trace(hi, lo);
  assert((hi - lo + 1) % 4 == 0);
  while (lo <= hi) {
    a.push_back(lo++), a.push_back(hi--);
    b.push_back(lo++), b.push_back(hi--);
  }
  ll diff = accumulate(a.begin(), a.end(), 0ll);
  diff -= accumulate(b.begin(), b.end(), 0ll);
  cout << abs(diff) << "\n";
  cout << sz(a) << " ";
  for (int i = 0; i < sz(a); ++i) {
    cout << a[i] << (i == sz(a) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
