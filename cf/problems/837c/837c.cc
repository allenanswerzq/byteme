/* created   : 2020-03-15 15:49:36
 * accepted  : 2020-03-15 16:14:55
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

const int N = 120;
pii rect[N];
int n, a, b;

int go(int x, int y) {
  int ans = 0;
  for (int rotate_a = 0; rotate_a < 2; rotate_a++) {
    for (int rotate_b = 0; rotate_b < 2; rotate_b++) {
      pii r1 = rect[x];
      pii r2 = rect[y];
      if (rotate_a == 1) {
        swap(r1.x, r1.y);
      }
      if (rotate_b == 1) {
        swap(r2.x, r2.y);
      }
      // [][]
      // []
      {
        int w = r1.y + r2.y;
        int h = max(r1.x, r2.x);
        if (w <= b && h <= a) {
          ans = max(ans, r1.x * r1.y + r2.x * r2.y);
        }
      }
      // []
      // []
      {
        int w = max(r1.y, r2.y);
        int h = r1.x + r2.x;
        if (w <= b && h <= a) {
          ans = max(ans, r1.x * r1.y + r2.x * r2.y);
        }
      }
    }
  }
  return ans;
}

void solve() {
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> rect[i].x >> rect[i].y;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans = max(ans, go(i, j));
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
