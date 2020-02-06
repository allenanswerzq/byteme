/* created   : 2020-02-04 20:05:02
 * accepted  : 2020-02-04 21:32:13
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
  vector<int> a(n + 1);
  unordered_map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int gold = cnt[a[1]];
  int silver = 0;
  for (int i = gold + 1; i <= n; ) {
    silver += cnt[a[i]];
    if (silver > gold) {
      break;
    }
    i += cnt[a[i]];
  }
  if (silver <= gold) {
    cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
    return;
  }
  int bronze = 0;
  int last = -1;
  for (int i = gold + silver + 1; i <= n; ) {
    bronze += cnt[a[i]];
    last = a[i];
    if (bronze > gold) {
      break;
    }
    i += cnt[a[i]];
  }
  int tot = gold + silver + bronze;
  if (bronze <= gold || tot > n / 2) {
    cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
    return;
  }
  for (int i = tot + 1; i <= n; ) {
    int t = cnt[a[i]];
    if (tot + t <= n / 2) {
      tot += t;
      last = a[i];
      bronze += t;
    }
    else {
      break;
    }
    i += t;
  }
  trace(n, gold, silver, bronze, last, tot);
  for (int i = tot + 1; i <= n; i++) {
    if (last > 0 && a[i] >= last) {
      cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
      return;
    }
  }
  cout << gold << ' ' << silver << ' ' << bronze << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
