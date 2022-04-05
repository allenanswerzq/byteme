/* created   : 2020-11-04 10:46:25
 * accepted  : 2020-11-04 22:02:53
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, M, K; cin >> N >> M >> K;
  multiset<int> st;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    st.insert(x);
  }
  vector<int> A(M);
  for (auto& a : A) {
    cin >> a;
  }
  sort(all(A));
  int ans = 0;
  for (int i = 0; i < M; i++) {
    auto it = st.lower_bound(A[i] - K);
    auto pt = st.upper_bound(A[i] + K);
    if (it != pt) {
      ans++;
      st.erase(it);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
