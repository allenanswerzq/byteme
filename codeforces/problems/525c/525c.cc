/* created   : 2020-05-02 15:17:57
 * accepted  : 2020-05-02 16:04:20
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a), greater<int>());
  vector<int> v;
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] - a[i + 1] < 2) {
      v.push_back(a[i + 1]);
      i++;
    }
  }
  trace(v);
  ll ans = 0;
  for (int i = 0; i + 1 < (int) v.size(); i += 2) {
    ans += v[i] * 1ll * v[i + 1];
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
