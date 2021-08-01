/* created   : 2021-08-01 08:03:52
 * accepted  : 2021-08-01 09:41:07
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = unsigned long long;
using ar = array<int, 2>;

ll go(vector<ll> & pre, vector<ll>& num, int x) {
  int p = upper_bound(all(num), x) - num.begin();
  assert(p >= 1);
  ll ans = pre[p];
  if (x > num[p - 1]) {
    ans += num[p] * (x - num[p - 1]);
  }
  return ans;
}

void solve() {
  set<ll> st;
  for (int len = 1; len <= 10; len++) {
    for (int i = 0; i < (1 << len); i++) {
      ll t = 0;
      for (int j = 0; j < len; j++) {
        if ((i >> j) & 1) {
          t += 4 * (ll) pow(10, j);
        }
        else {
          t += 7 * (ll) pow(10, j);
        }
      }
      st.insert(t);
    }
  }
  st.insert(0);
  vector<ll> num(all(st));
  vector<ll> pre(num.size() + 1);
  for (int i = 1; i < num.size(); i++) {
    pre[i + 1] = pre[i] + num[i] * 1ll * (num[i] - num[i - 1]);
  }
  // trace(num);
  // trace(pre);
  int L, R; cin >> L >> R;
  cout << go(pre, num, R) - go(pre, num, L - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
