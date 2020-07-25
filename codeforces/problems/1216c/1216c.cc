/* created   : 2020-03-02 15:29:44
 * accepted  : 2020-03-02 18:54:55
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

// x1     x2
// |------|
//     x3     x4
//     |------|
bool check(int x1, int x2, int x3, int x4) {
  return (x1 <= x3 && x3 <= x2) || (x3 <= x1 && x1 <= x4);
}

struct Rectangle {
  pii bottom;
  pii top;
  Rectangle(int x1, int y1, int x2, int y2) {
    bottom = pii{x1, y1};
    top = pii{x2, y2};
  }
  Rectangle() {}
};

// debugstream& operator<<(debugstream& os, Rectangle& a) {
//   return os << a.bottom << ' ' << a.top;
// }

// Whether b is inside a.
bool inside(Rectangle b, Rectangle a) {
  bool ok = true;
  ok &= (a.bottom.x <= b.bottom.x && b.bottom.x <= a.top.x);
  ok &= (a.bottom.x <= b.top.x && b.top.x <= a.top.x);
  ok &= (a.bottom.y <= b.bottom.y && b.bottom.y <= a.top.y);
  ok &= (a.bottom.y <= b.top.y && b.top.y <= a.top.y);
  trace(b, a);
  return ok;
}

void solve() {
  vector<Rectangle> a(3);
  for (int i = 0; i < 3; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    a[i].bottom = make_pair(x1, y1);
    a[i].top = make_pair(x2, y2);
  }
  if (inside(a[0], a[1]) || inside(a[0], a[2])) {
    cout << "NO" << '\n';
    return;
  }
  bool ok = false;
  if (check(a[1].bottom.x, a[1].top.x, a[2].bottom.x, a[2].top.x)) {
    int ix = min(a[1].bottom.x, a[2].bottom.x);
    int ax = max(a[1].top.x, a[2].top.x);
    int iy = max(a[1].bottom.y, a[2].bottom.y);
    int ay = min(a[1].top.y, a[2].top.y);
    trace(ix, ax, iy, ay);
    if (inside(a[0], Rectangle(ix, iy, ax, ay))) {
      ok = true;
    }
  }
  trace(ok);
  if (check(a[1].bottom.y, a[1].top.y, a[2].bottom.y, a[2].top.y)) {
    int ix = max(a[1].bottom.x, a[2].bottom.x);
    int ax = min(a[1].top.x, a[2].top.x);
    int iy = min(a[1].bottom.y, a[2].bottom.y);
    int ay = max(a[1].top.y, a[2].top.y);
    trace(ix, ax, iy, ay);
    if (inside(a[0], Rectangle(ix, iy, ax, ay))) {
      ok = true;
    }
  }
  trace(ok);
  cout << (ok ? "NO" : "YES") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
