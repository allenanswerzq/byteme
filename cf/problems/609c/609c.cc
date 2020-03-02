/* created   : 2020-03-02 09:59:19
 * accepted  : 2020-03-02 10:16:20
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
  vector<int> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll avg = sum / n;
  ll extra = sum - avg * n;
  trace(avg, extra);
  vector<int> b(n, avg);
  for (int i = 0; i < n && extra; i++) {
    b[i] += 1;
    extra--;
  }
  assert(extra == 0);
  trace(extra, b);
  sort(all(a), greater<int>());
  trace(a, b);
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += abs(a[i] - b[i]);
  }
  trace(cnt);
  cout << cnt / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
