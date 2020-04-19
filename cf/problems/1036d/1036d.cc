/* created   : 2020-04-19 21:47:13
 * accepted  : 2020-04-19 22:18:16
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m; cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int p = 0;
  int q = 0;
  int ans = 0;
  while (p < n && q < m) {
    trace(p, q);
    if (a[p] == b[q]) {
      p++;
      q++;
      ans++;
    }
    else {
      for (ll sa = a[p++], sb = b[q++]; ;) {
        if (sa == sb) {
          ans++;
          break;
        }
        else if (sa > sb) {
          if (q < m) {
            sb += b[q++];
          }
          else {
            cout << -1 << '\n';
            return;
          }
        }
        else {
          if (p < n) {
            sa += a[p++];
          }
          else {
            cout << -1 << '\n';
            return;
          }
        }
      }
    }
  }
  if (p != n || q != m) {
    cout << -1 << '\n';
    return;
  }
  assert(p == n && q == m);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
