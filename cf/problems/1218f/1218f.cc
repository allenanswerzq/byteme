/* created   : 2020-03-30 22:18:54
 * accepted  : 2020-03-30 22:41:03
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, k; cin >> n >> k;
  vector<int> lift(n);
  for (int i = 0; i < n; i++) {
    cin >> lift[i];
  }
  ll add; cin >> add;
  vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  ll ans = 0;
  set<int> st;
  for (int i = 0; i < n; i++) {
    st.insert(cost[i]);
    if (k < lift[i]) {
      trace(i, st, lift[i]);
      while (!st.empty() && k < lift[i]) {
        k += add;
        ans += *st.begin();
        st.erase(st.begin());
      }
      if (st.empty() && k < lift[i]) {
        cout << -1 << '\n';
        return;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
