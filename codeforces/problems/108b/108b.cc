/* created   : 2020-03-29 16:15:30
 * accepted  : 2020-03-29 16:53:53
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  for (int i = 0; i + 1 < a.size(); i++) {
    if (dbg(a[i] == 1)) continue;
    if (!(a[i + 1] >= 2 * a[i])) {
      // trace(i, a[i], a[i + 1]);
      cout << "YES" << '\n';
      return;
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
