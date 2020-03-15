/* created   : 2020-03-15 17:38:46
 * accepted  : 2020-03-15 17:51:44
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
typedef pair<ll, string> pls;

void solve() {
  int n, k, m; cin >> n >> k >> m;
  vector<string> word(n);
  for (int i = 0; i < n; i++) {
    cin >> word[i];
  }
  vector<ll> cost(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  unordered_map<string, int> stog;
  unordered_map<int, set<ll>> grp;
  for (int i = 0; i < k; i++) {
    int x; cin >> x;
    for (int j = 0; j < x; j++) {
      int y; cin >> y;
      y--;
      grp[i].insert(cost[y]);
      stog[word[y]] = i;
    }
  }
  string msg;
  ll ans = 0;
  while (cin >> msg) {
    assert(grp.count(stog[msg]));
    ans += *grp[stog[msg]].begin();
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
