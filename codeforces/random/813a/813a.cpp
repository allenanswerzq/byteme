//=============================================================
// Name        : 813a
// Date        : Sat Jun  1 16:11:50 CST 2019
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
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int m;
  cin >> m;
  ll ret = -1;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    if (x <= sum && sum <= y) {
      ret = sum;
      break;
    } else if (sum <= x) {
      ret = x;
      break;
    }
  }
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
