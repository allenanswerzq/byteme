/* created   : 2020-11-05 21:37:04
 * accepted  : 2020-11-05 21:40:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) cin >> a;
  set<int> st;
  int ans = 0;
  for (int i = 0, j = 0; i < N; i++) {
    while (j < N && !st.count(A[j])) {
      st.insert(A[j++]);
    }
    ans = max(ans, j - i);
    st.erase(A[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
