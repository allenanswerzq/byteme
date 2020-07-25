/* created   : 2020-02-08 13:15:37
 * accepted  : 2020-02-08 14:14:17
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
  ll a, b, f, k;
  cin >> a >> b >> f >> k;
  vector<int> st;
  bool flag = true;
  int t = f;
  st.push_back(0);
  for (int i = 0; i < k; i++) {
    st.push_back(t);
    if (flag) {
      t += a - f + a - f;
    }
    else {
      t += f + f;
    }
    flag ^= 1;
  }
  st.push_back(a * k);
  trace(st);
  int tot = b;
  int ans = 0;
  for (int i = 1; i < st.size(); i++) {
    int dist = st[i] - st[i - 1];
    if (tot < dist) {
      ans++;
      tot = b;
    }
    // trace(i, dist, tot, ans);
    if (tot >= dist) {
      tot -= dist;
    }
    else {
      cout << -1 << '\n';
      return;
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
