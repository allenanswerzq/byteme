/* created   : 2021-08-08 15:46:22
 * accepted  : 2021-08-08 17:40:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  int N, M; cin >> N >> M;
  set<ar> st;
  for (int i = 0; i < N; i++) {
    ll l, r; cin >> l >> r;
    st.insert({l, r});
  }
  vector<ll> ans;
  for (int i = 0; i < M; i++) {
    ll x; cin >> x;
    // trace(st);
    assert(st.size());
    auto p = st.upper_bound({x, (ll)1e18 + 7});
    if (p == st.begin()) {
      ll lo = (*p)[0], hi = (*p)[1];
      ans.push_back(lo);
      st.erase(p);
      if (lo + 1 <= hi) {
        st.insert({lo + 1, hi});
      }
    }
    else {
      auto t = std::prev(p);
      ll lo = (*t)[0], hi = (*t)[1];
      if (lo <= x && x <= hi) {
        // case 1: x is contained inside an interval
        ans.push_back(x);
        st.erase(t);
        if (x - 1 >= lo) {
          st.insert({lo, x - 1});
        }
        if (x + 1 <= hi) {
          st.insert({x + 1, hi});
        }
      }
      else if (p != st.end()) {
        assert(p != st.end());
        ll pi = (*p)[0], pr = (*p)[1];
        // |_____t___| x     |____p___|
        if (abs(x - hi) <= abs(x - pi)) {
          ans.push_back(hi);
          st.erase(t);
          if (hi - 1 >= lo) {
            st.insert({lo, hi - 1});
          }
        }
        else {
          ans.push_back(pi);
          st.erase(p);
          if (pi + 1 <= pr) {
            st.insert({pi + 1, pr});
          }
        }
      }
      else {
        assert(t != st.end());
        ans.push_back(hi);
        st.erase(t);
        if (hi - 1 >= lo) {
          st.insert({lo, hi - 1});
        }
      }
    }
  }
  for (int i = 0; i < M; i++) {
    cout << ans[i] << (i == M - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
