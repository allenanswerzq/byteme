/* created   : 2020-05-08 23:19:16
 * accepted  : 2020-05-08 23:44:47
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<ll> a(n);
  map<ll, set<int>> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]].insert(i);
  }
  while (!mp.empty()) {
    ll v = mp.begin()->x;
    auto& st = mp.begin()->y;
    trace(v, st, a);
    if (st.size() <= 1) {
      mp.erase(mp.begin());
      continue;
    }
    ll x = *st.begin();
    st.erase(st.begin());
    ll y = *st.begin();
    st.erase(st.begin());
    a[x] = -1;
    a[y] = 2 * v;
    mp[2 * v].insert(y);
  }
  vector<ll> ans;
  for (int i = 0; i < n; i++) {
    if (a[i] != -1) {
      ans.push_back(a[i]);
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
