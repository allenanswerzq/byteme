//=============================================================
// Name        : 144b
// Date        : Wed Jul  3 09:29:22 CST 2019
// Accepted    : Wed Jul  3 20:47:29 CST 2019
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

struct node {
  int x;
  int y;
  int r;
};

bool dist(int x, int y, node& a) {
  int d = (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
  return d <= a.r * a.r;
}

void solve() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) {
    swap(x1, x2);
  }
  if (y1 > y2) {
    swap(y1, y2);
  }
  int n;
  cin >> n;
  vector<node> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].r;
  }
  int ans = 0;
  for (int x = x1; x <= x2; ++x) {
    vector<int> v;
    if (x == x1 || x == x2) {
      v.resize(y2 - y1 + 1);
      iota(v.begin(), v.end(), y1);
    }
    else {
      v.push_back(y1);
      v.push_back(y2);
    }
    for (auto y : v) {
      bool ok = 0;
      for (int k = 0; k < n; ++k) {
        if (dist(x, y, a[k])) {
          ok = 1;
          break;
        }
      }
      trace(x, y, ok);
      if (!ok) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
