//=============================================================
// Name        : 900b
// Date        : Mon Jun 17 20:58:03 CST 2019
// Accepted    : Mon Jun 17 21:41:58 CST 2019
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
  ll a, b, c;
  cin >> a >> b >> c;
  vector<int> re;
  for (int i = 0; i < (int) 1e5; ++i) {
    a *= 10;
    int div = a / b;
    int rem = a % b;
    re.push_back(div);
    a = rem;
  }
  // trace(re);
  int ix = -1;
  for (int i = 0; i < sz(re); ++i) {
    if (c == re[i]) {
      ix = i + 1;
      break;
    }
  }
  cout << ix << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(120) << fixed;
  solve();
  return 0;
}
