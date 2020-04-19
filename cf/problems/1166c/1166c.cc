/* created   : 2020-04-17 08:12:28
 * accepted  : 2020-04-17 08:47:30
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve1() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  sort(all(a));
  ll ans = 0;
  int lo = 0;
  for (int i = 0; i < n; i++) {
    while (2 * a[lo] < a[i]) {
      lo++;
    }
    // a[i] <= 2 * a[lo];
    // lo ... i
    ans += i - lo;
  }
  cout << ans << '\n';
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  sort(all(a));
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int p = lower_bound(a.begin(), a.begin() + i, (a[i] + 1) / 2) - a.begin();
    // a[i] <= 2 * a[lo];
    ans += i - p;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
