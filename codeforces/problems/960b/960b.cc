/* created   : 2020-02-16 10:31:24
 * accepted  : 2020-02-16 10:37:16
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
  int n, k1, k2; cin >> n >> k1 >> k2;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    int b; cin >> b;
    c[i] = abs(a[i] - b);
  }
  priority_queue<int> pq(all(c));
  int k = k1 + k2;
  while (!pq.empty() && k) {
    int x = pq.top();
    pq.pop();
    if (x == 0) {
      break;
    }
    x -= 1;
    pq.push(x);
    k--;
  }
  ll ans = 0;
  if (k % 2) {
    ans += 1;
  }
  while (!pq.empty()) {
    ll x = pq.top();
    ans += x * x;
    pq.pop();
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
