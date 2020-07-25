/* created   : 2020-02-10 12:56:58
 * accepted  : 2020-02-10 15:03:21
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
  vector<int> a(n + 1);
  vector<int> pr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pr[i] = pr[i - 1] | a[i];
  }
  vector<int> sf(n + 2);
  for (int i = n; i >= 1; i--) {
    sf[i] = sf[i + 1] | a[i];
  }
  trace(a, pr, sf);
  int ans = -1;
  int pos = -1;
  for (int i = 1; i <= n; i++) {
    int cur = a[i] & ~(pr[i - 1] | sf[i + 1]);
    if (cur > ans) {
      ans = cur;
      pos = i;
    }
    trace(i, cur, ans);
  }
  assert(pos != -1);
  swap(a[1], a[pos]);
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
