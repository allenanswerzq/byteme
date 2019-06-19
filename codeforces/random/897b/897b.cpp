//=============================================================
// Name        : 897b
// Date        : Sat Jun 15 15:56:22 CST 2019
// Accepted    : Sat Jun 15 17:10:08 CST 2019
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
  int n, mod;
  cin >> n >> mod;
  ll sum = 0;
  int s = 1;
  for (int i = 0; i < n; ++i) {
    string a = to_string(s);
    reverse(a.begin(), a.end());
    string zcy = to_string(s) + a;
    sum += stoll(zcy) % mod;
    sum %= mod;
    s++;
  }
  cout << sum << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
