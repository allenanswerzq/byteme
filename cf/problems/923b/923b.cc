/* created   : 2020-04-23 23:47:41
 * accepted  : 2020-04-24 12:52:30
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<ll> st;
  ll ps = 0;
  vector<ll> ans;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    st.insert(a[i] + ps);
    auto it = st.upper_bound(ps + t);
    ll cur = 0;
    for (auto p = st.begin(); p != it; p++) {
      cur += *p - ps;
    }
    st.erase(st.begin(), it);
    cur += st.size() * t;
    ps += t;
    ans.push_back(cur);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
