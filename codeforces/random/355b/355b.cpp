//=============================================================
// Name        : 355b
// Date        : Sat Jun  1 21:21:55 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  vector<ll> p(4);
  for (int i = 0; i < 4; ++i) {
    cin >> p[i];
  }
  int n, m;
  cin >> n >> m;
  ll a1 = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a1 += min(x * p[0], p[1]);
  }
  ll a2 = 0;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    a2 += min(x * p[0], p[1]);
  }
  ll ret = p[3];
  ret = min(ret, 2 * p[2]);
  ret = min(ret, a1 + a2);
  ret = min(ret, a1 + p[2]);
  ret = min(ret, a2 + p[2]);
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
