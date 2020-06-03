/* created   : 2020-06-03 19:44:54
 * accepted  : 2020-06-03 20:21:04
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int n;

void solve() {
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.push_back(0), n++;
  trace(a, n);
  vector<int> stk;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (stk.empty() || a[i] >= a[stk.back()]) {
      stk.push_back(i);
      continue;
    }
    while (!stk.empty() && a[stk.back()] > a[i]) {
      ll height = a[stk.back()];
      stk.pop_back();
      ll lo = stk.empty() ? -1 : stk.back();
      ans = max(ans, (i - lo - 1) * height);
    }
    stk.push_back(i);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n && n) {
    solve();
  }
  return 0;
}
