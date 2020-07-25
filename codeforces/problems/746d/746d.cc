/* created   : 2020-03-03 22:26:12
 * accepted  : 2020-03-03 23:05:39
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

void solve() {
  int n, k, a, b; cin >> n >> k >> a >> b;
  char ca = 'G';
  char cb = 'B';
  if (a < b) {
    swap(a, b);
    swap(ca, cb);
  }
  string ans;
  int cnt = 0;
  while (a > 0 && b > 0) {
    int ia = min(a, k);
    ans += string(ia, ca);
    a -= ia;
    ans += string(1, cb);
    b--;
    cnt++;
  }
  trace(a, b, k);
  if (a > 0) {
    if (a > k) {
      cout << "NO" << '\n';
    }
    else {
      ans += string(a, ca);
      cout << ans << '\n';
    }
  }
  else {
    if (b > cnt * (k - 1)) {
      cout << "NO" << '\n';
    }
    else {
      string cur;
      for (int i = 0; i < (int) ans.size(); i++) {
        if (ans[i] == ca) {
          cur += ca;
        }
        else {
          int d = min(k - 1, b);
          cur += string(d + 1, cb);
          b -= d;
        }
      }
      assert((int) cur.size() == n);
      cout << cur << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
