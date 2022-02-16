/* created   : 2022-02-16 00:02:41
 * accepted  : 2022-02-16 23:22:04
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  unordered_map<int, set<int>> mp;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]].insert(i);
  }
  trace(A);
  int nxt = 0;
  int i = 0;
  set<int> st;
  vector<int> ans;
  while (i < N) {
    trace(i, nxt, mp);
    if (mp.count(nxt) && mp[nxt].size() > 0) {
      assert(mp[nxt].size());
      int j = *mp[nxt].begin();
      // [i...j]
      // [x...nxt]
      st.clear();
      for (int k = i; k <= j; k++) {
        st.insert(A[k]);
        mp[A[k]].erase(k);
      }
      trace(i, j, st);
      assert(st.size());
      int len = j - i + 1;
      int tmp = nxt;
      for (int t = tmp; t < tmp + len; t++) {
        if (st.count(t)) {
          nxt++;
        }
      }
      assert(st.size());
      if (nxt != *st.rbegin() + 1) {
        ans.push_back(nxt);
        nxt = 0;
      }
      i = j + 1;
    }
    else {
      ans.push_back(nxt);
      nxt = 0;
      i++;
    }
  }
  int m = ans.size();
  cout << m << "\n";
  for (int j = 0; j < m; j++) {
    cout << ans[j] << (j == m - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
