/* created   : 2020-04-28 22:10:58
 * accepted  : 2020-04-28 22:37:12
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

vector<pair<int, int>> factors(int x) {
  vector<pair<int, int>> ans;
  for (int i = 2; i * i <= x; i++) {
    int cnt = 0;
    while (x % i == 0) {
      x /= i;
      cnt++;
    }
    if (cnt > 0) {
      ans.push_back({i, cnt});
    }
  }
  if (x > 1) {
    ans.push_back({x, 1});
  }
  return ans;
}

int big(int x) {
  int r = 1;
  int cnt = 0;
  while (r < x) {
    r <<= 1;
    cnt++;
  }
  return cnt;
}

void solve() {
  int n; cin >> n;
  auto fact = factors(n);
  int ans = 1;
  int mx = 0;
  trace(fact);
  for (auto it : fact) {
    ans *= it.x;
    mx = max(mx, dbg(big(it.y)));
  }
  bool ok = false;
  for (auto it : fact) {
    if (it.y != (1 << mx)) {
      ok = true;
      break;
    }
  }
  trace(mx, ok);
  cout << ans << " " << (mx + ok) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
