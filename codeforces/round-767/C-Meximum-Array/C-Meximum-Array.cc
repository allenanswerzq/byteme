/* created   : 2022-02-16 00:02:41
 * accepted  : 2022-02-18 08:55:22
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
  auto compute_next_position = [&](int i, int nxt) {
    if (!mp.count(nxt)) {
      return -1;
    }
    auto & st = mp[nxt]; // NOTE: should use a reference here
    auto it = st.lower_bound(i);
    if (it == st.end()) {
      return -1;
    }
    return *it;
  };
  trace(A);
  vector<int> ans;
  vector<int> f(N + 1);
  int i = 0;
  int nxt = 0;
  int val = 0;
  while (i < N) {
    int j = compute_next_position(i, nxt);
    if (j == -1) {
      ans.push_back(nxt);
      nxt = 0;
      i++;
      continue;
    }
    val++;
    while (j != -1) {
      // [i...j]
      for (int k = i; k <= j; k++) {
        f[A[k]] = val;
        while (f[nxt] == val) {
          nxt++;
        }
      }
      trace(i, j, nxt, val);
      i = j + 1;
      j = compute_next_position(i, nxt);
    }
    ans.push_back(nxt);
    nxt = 0;
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
