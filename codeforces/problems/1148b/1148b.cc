/* created   : 2020-05-03 21:19:14
 * accepted  : 2020-05-04 12:46:10
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<int> arrive_a(n);
  for (auto &x : arrive_a) {
    cin >> x;
    x += ta;
  }
  vector<int> depart_b(m);
  for (auto &x : depart_b) {
    cin >> x;
  }
  if (k >= min(n, m)) {
    cout << -1 << "\n";
    return;
  }
  sort(all(arrive_a));
  sort(all(depart_b));
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    int depart = arrive_a[i];
    int p = lower_bound(all(depart_b), depart) - depart_b.begin();
    p += (k - i);
    if (p >= m) {
      // Cancle all filghts from b-->c
      cout << -1 << "\n";
      return;
    }
    ans = max(ans, depart_b[p] + tb);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
