/* created   : 2020-04-29 11:50:37
 * accepted  : 2020-04-29 19:18:41
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int h, n; cin >> h >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }
  ll ans = 0;
  a.push_back(0);
  // <---
  //  1011
  //     -
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i + 1] > 1) {
      ans++;
    }
    else {
      // 111
      //   -
      i++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
