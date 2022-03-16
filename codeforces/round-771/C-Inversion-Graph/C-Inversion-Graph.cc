/* created   : 2022-03-15 21:40:26
 * accepted  : 2022-03-16 10:03:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  set<int> st;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x = A[i];
    auto it = st.lower_bound(x);
    if (it == st.end()) {
      // if no values greater than x
      // -----x
      if (st.size() && *st.rbegin() == i) {
        ans++;
        st.clear();
      }
      else {
        // continues;
      }
    }
    st.insert(x);
  }
  cout << ans + !st.empty() << "\n";
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
