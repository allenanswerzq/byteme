/* created   : 2019-09-13 17:15:01
 * accepted  : 2019-09-13 17:27:36
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 1.5e5 + 7;

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  trace(v);
  int ans = 0;
  vector<int> use(N);
  for (int i = 0; i < n; i++) {
    int x = v[i];
    if (0 < x - 1 && !use[x - 1]) {
      ans++;
      use[x - 1] = 1;
    }
    else if (!use[x]) {
      ans++;
      use[x] = 1;
    }
    else if (x + 1 <= 150001 && !use[x + 1]) {
      ans++;
      use[x + 1] = 1;
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
