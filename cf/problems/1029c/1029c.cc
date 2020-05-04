/* created   : 2020-05-03 10:16:02
 * accepted  : 2020-05-03 10:44:39
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve2() {
  int n; cin >> n;
  vector<pair<int, int>> lt(n);
  vector<pair<int, int>> rt(n);
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    lt[i] = {x, i};
    rt[i] = {y, i};
  }
  sort(all(lt));
  sort(all(rt));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int mx = lt[n - 1].x;
    int mi = rt[0].x;
    if (i == lt[n - 1].y) {
      mx = lt[n - 2].x;
    }
    if (i == rt[0].y) {
      mi = rt[1].x;
    }
    trace(i, mi, mx);
    ans = max(ans, mi - mx);
  }
  cout << ans << "\n";
}

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }
  int mx = 0;
  int mi = 1e9 + 7;
  vector<pair<int, int>> pf(n);
  for (int i = 0; i < n; i++) {
    pf[i] = {mx, mi};
    mx = max(mx, a[i].x);
    mi = min(mi, a[i].y);
  }
  mx = 0;
  mi = 1e9 + 7;
  vector<pair<int, int>> sf(n);
  for (int i = n - 1; i >= 0; i--) {
    sf[i] = {mx, mi};
    mx = max(mx, a[i].x);
    mi = min(mi, a[i].y);
  }
  trace(pf, sf);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = min(pf[i].y, sf[i].y) - max(pf[i].x, sf[i].x);
    ans = max(ans, cur);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
