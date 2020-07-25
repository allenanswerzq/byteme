/* created   : 2020-05-01 18:37:07
 * accepted  : 2020-05-01 18:49:30
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  trace(a);
  vector<int> ans;
  ans.push_back(0);
  int s = 1;
  int f = a[s].x;
  int g = a[s].y;
  ans.push_back(s);
  if (a[f].x == g || a[f].y == g) {
    ans.push_back(f);
    ans.push_back(g);
  }
  else if (a[g].x == f || a[g].y == f) {
    ans.push_back(g);
    ans.push_back(f);
  }
  else {
    assert(false);
  }
  for (int i = 2; i + 1 <= n; i++) {
    int x = ans[i];
    int y = ans[i + 1];
    if (a[x].x != y) {
      ans.push_back(a[x].x);
    }
    else {
      ans.push_back(a[x].y);
    }
  }
  trace(ans);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
