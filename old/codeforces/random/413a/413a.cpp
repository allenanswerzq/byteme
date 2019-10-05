//=============================================================
// Name        : 413a
// Date        : Tue Jun  4 17:35:49 CST 2019
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
  int n, m, mi, mx;
  cin >> n >> m >> mi >> mx;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  int nx = *max_element(a.begin(), a.end());
  int ni = *min_element(a.begin(), a.end());
  int cnt = 0;
  if (nx == mx) {
    cnt++;
  }
  if (ni == mi) {
    cnt++;
  }
  if (n - m < 2 - cnt || nx > mx || ni < mi) {
    cout << "Incorrect\n";
  } else {
    cout << "Correct\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
