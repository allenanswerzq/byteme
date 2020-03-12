/* created   : 2020-03-11 23:22:58
 * accepted  : 2020-03-12 00:15:22
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

void solve() {
  int n; cin >> n;
  vector<int> a(n - 1);
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  vector<int> t(n);
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      t[0] = i;
      t[1] = j;
      if (!(a[0] == (t[0] | t[1]) && b[0] == (t[0] & t[1]))) continue;
      bool ok = true;
      for (int k = 1; k < n - 1; k++) {
        int cur = -1;
        int cnt = 0;
        for (int x = 0; x <= 3; x++) {
          if ((t[k] | x) == a[k] && (t[k] & x) == b[k]) {
            cur = x;
            cnt++;
          }
        }
        if (cur == -1) {
          ok = false;
          break;
        }
        assert(cnt == 1);
        t[k + 1] = cur;
      }
      if (ok) {
        cout << "YES" << '\n';
        for (int k = 0; k < n; k++) {
          cout << t[k] << (k == n - 1 ? '\n' : ' ');
        }
        return;
      }
    }
  }
  cout << "NO" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
