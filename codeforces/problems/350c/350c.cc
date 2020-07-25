/* created   : 2020-05-04 17:41:29
 * accepted  : 2020-05-04 17:51:34
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

bool comp(pair<int, int>& a, pair<int, int>& b) {
  return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
}

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  sort(all(a), comp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i].x;
    int y = a[i].y;
    if (abs(x) > 0) {
      ans++;
    }
    if (abs(y) > 0) {
      ans++;
    }
    ans++;
    if (abs(x) > 0) {
      ans++;
    }
    if (abs(y) > 0) {
      ans++;
    }
    ans++;
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    int x = a[i].x;
    int y = a[i].y;
    char cx = (x < 0 ? 'L' : 'R');
    char cy = (y < 0 ? 'D' : 'U');
    if (abs(x) > 0) {
      cout << 1 << " " << abs(x) << " " << cx << "\n";
    }
    if (abs(y) > 0) {
      cout << 1 << " " << abs(y) << " " << cy << "\n";
    }
    cout << 2 << "\n";
    if (abs(x) > 0) {
      cout << 1 << " " << abs(x) << " " << (x < 0 ? 'R' : 'L') << "\n";
    }
    if (abs(y) > 0) {
      cout << 1 << " " << abs(y) << " " << (y < 0 ? 'U' : 'D') << "\n";
    }
    cout << 3 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
