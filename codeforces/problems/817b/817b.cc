/* created   : 2020-03-09 23:17:57
 * accepted  : 2020-03-10 00:29:15
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
  int n; cin >> n;
  unordered_map<int, ll> cnt;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(all(a));
  set<int> st;
  for (int i = 0; i < 3; i++) {
    st.insert(a[i]);
  }
  trace(a);
  ll ans = 0;
  trace(st);
  int na = st.size();
  if (na == 3) {
    ans += cnt[a[0]] * cnt[a[1]] * cnt[a[2]];
  }
  else if (na == 2) {
    ll t = cnt[a[0]];
    ll x = cnt[a[0 + t]];
    if (t >= 2) {
      ans += t * (t - 1) / 2 * x;
    }
    else if (x >= 2) {
      ans += x * (x - 1) / 2 * t;
    }
    else {
      assert(false);
    }
  }
  else if (na == 1) {
    ll t = cnt[a[0]];
    ans += t * (t - 1) * (t - 2) / 6;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
