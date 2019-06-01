//============================================================================
// Name        : 629b
// Date        : Sun Apr 21 22:21:41 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

struct Node {
  char c;
  int x, y;
  friend dbstream& operator<<(dbstream& os, Node& b) {
    return os << b.c << " " << b.x << " " << b.y << "\n";
  }
};

void solve() {
  int n;
  cin >> n;
  vector<Node> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].c >> a[i].x >> a[i].y;
  }
  sort(all(a), [](Node& a, Node& b) {
    if (a.y == b.y) {
      return a.x < b.x;
    } else {
      return a.y < b.y;
    }
  });
  trace(a);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    int m = 0, f = 0;
    for (int j = i; j < n; ++j) {
      if (a[j].x <= a[i].y && a[i].y <= a[j].y) {
        m += (a[j].c == 'M');
        f += (a[j].c == 'F');
      }
    }
    trace(i, m, f);
    ret = max(ret, 2 * min(m, f));
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
