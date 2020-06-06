/* created   : 2020-06-05 20:11:06
 * accepted  : 2020-06-06 07:46:53
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(all(a));
  int ans = 0;
  int dir = -1;
  int last = 1e9;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && a[j].x == a[i].x) j++;
    // [i...j-1]
    int mi = a[i].y, mx = a[j - 1].y;
    if (dir == -1) {
      // decreasing
      if (mx > last) {
        dir = 1, last = mx;
        ans++;
      }
      else {
        dir = -1, last = mi;
      }
    }
    else {
      // increasing
      if (mi > last) {
        dir = 1, last = mx;
      }
      else {
        dir = -1, last = mi;
      }
    }
    i = j;
  }
  cout << ans + (dir == -1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
