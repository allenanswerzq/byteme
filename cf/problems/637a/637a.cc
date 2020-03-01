/* created   : 2020-03-01 21:08:41
 * accepted  : 2020-03-01 21:10:23
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
  int n; cin >> n;
  unordered_map<int, int> cnt;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    mx = max(mx, cnt[a[i]]);
  }
  cnt.clear();
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] == mx) {
      cout << a[i] << '\n';
      return;
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
