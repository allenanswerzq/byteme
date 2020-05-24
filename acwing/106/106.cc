/* created   : 2020-05-23 10:38:21
 * accepted  : 2020-05-23 10:42:33
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(all(a));
  int md = 0;
  if (n % 2) {
    md = a[n / 2];
  }
  else {
    md = (a[n / 2] + a[(n - 1) / 2]) / 2;
  }
  ll ans = 0;
  for (auto x : a) {
    ans += abs(x - md);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
