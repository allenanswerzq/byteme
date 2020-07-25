/* created   : 2020-05-10 10:18:37
 * accepted  : 2020-05-10 10:37:06
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double mx = 0;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int p = upper_bound(a.begin() + i + 1, a.end(), a[i] + k) - a.begin();
    p--;
    if (p - i >= 2) {
      mx = max(mx, (a[p] - a[i + 1]) * 1.0 / (a[p] - a[i]));
      ok = true;
    }
  }
  cout << (ok ? mx : -1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
