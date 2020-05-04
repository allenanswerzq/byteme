/* created   : 2020-05-03 22:28:31
 * accepted  : 2020-05-04 11:27:18
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  int hi = 0;
  pair<int, int> mx = {0, 0};
  for (int lo = 0; lo < n; lo++) {
    if (lo > hi) {
      hi = lo;
      cnt = 0;
    }
    while (hi < n) {
      if (cnt + !a[hi] > k) {
        break;
      }
      cnt += !a[hi];
      hi++;
    }
    trace(lo, hi, cnt);
    if (mx.y - mx.x < hi - lo) {
      mx = {lo, hi};
    }
    // Move lo one step forward.
    if (cnt > 0) {
      cnt -= !a[lo];
    }
  }
  trace(mx);
  cout << mx.y - mx.x << "\n";
  for (int i = mx.x; i < mx.y; i++) {
    a[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
