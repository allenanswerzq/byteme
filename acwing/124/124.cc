/* created   : 2020-05-31 18:12:20
 * accepted  : 2020-05-31 18:46:51
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
  ll t = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    t += a[i];
  }
  vector<int> s(n + 1);
  int avg = t / n;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i] - avg;
  }
  sort(s.begin() + 1, s.end());
  ll ans = 0;
  for (int i = 1; i <= n / 2; i++) {
    ans += s[n - i + 1] - s[i];
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
