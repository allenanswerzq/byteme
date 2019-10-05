//=============================================================
// Name        : 292b
// Date        : Sat Jun  1 15:33:20 CST 2019
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
  int n, m;
  cin >> n >> m;
  vector<vi> a(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x].pb(y);
    a[y].pb(x);
  }
  vi cnt(n);
  for (int i = 0; i < n; ++i) {
    cnt[sz(a[i])]++;
  }
  // trace(cnt);
  if (cnt[1] == 2 && cnt[2] == n - 2) {
    cout << "bus topology\n";
  } else if (cnt[2] == n) {
    cout << "ring topology\n";
  } else if (cnt[1] == n - 1 && cnt[n - 1] == 1) {
    cout << "star topology\n";
  } else {
    cout << "unknown topology\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
