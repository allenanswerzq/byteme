/* created   : 2020-06-01 19:38:29
 * accepted  : 2020-06-01 20:12:04
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<ll, ll>

bool comp(pii& a, pii& b) {
  return a.x + a.y < b.x + b.y;
}

void solve() {
  int n; cin >> n;
  vector<pii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  sort(all(a), comp);
  trace(a);
  ll ps = 0;
  ll mx = -1e9;
  for (int i = 0; i < n; i++) {
    mx = max(mx, ps - a[i].y);
    ps += a[i].x;
  }
  cout << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
