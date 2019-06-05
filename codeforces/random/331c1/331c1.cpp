//=============================================================
// Name        : 331c1
// Date        : Tue Jun  4 16:59:29 CST 2019
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
  ll a;
  cin >> a;
  int ret = 0;
  while (a) {
    trace(a);
    string b = to_string(a);
    int c = *max_element(b.begin(), b.end()) - '0';
    a = a - c;
    ret++;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
