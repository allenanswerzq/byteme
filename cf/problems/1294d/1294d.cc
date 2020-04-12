/* created   : 2020-04-10 23:40:18
 * accepted  : 2020-04-11 08:34:33
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, x; cin >> n >> x;
  set<pair<ll, int>> st;
  vector<int> cnt(x);
  for (int i = 0; i < x; i++) {
    st.insert({0, i});
  }
  for (int i = 0; i < n; i++) {
    int y; cin >> y;
    y %= x;
    st.erase({cnt[y], y});
    cnt[y]++;
    st.insert({cnt[y], y});
    auto it = *st.begin();
    ll ans = it.x * x + it.y;
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
