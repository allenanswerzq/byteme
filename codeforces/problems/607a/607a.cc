/* created   : 2020-04-12 10:37:22
 * accepted  : 2020-04-12 10:43:13
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].x--;
  }
  sort(all(a));
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    int p = lower_bound(all(a), make_pair(a[i].x - a[i].y, 0)) - a.begin() - 1;
    if (p < 0) {
      f[i] = 1;
    }
    else {
      f[i] = f[p] + 1;
    }
  }
  cout << n - *max_element(all(f)) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
