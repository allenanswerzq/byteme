/* created   : 2021-02-17 15:32:43
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  // 1 2 3 1 1
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  multiset<int> st;
  ll ans = 0;
  int cnt = 0;
  // NOTE: The time complexity of multiset's count is log(n) + c
  for (int lo = 0, hi = 0; lo < N && hi < N; lo++) {
    while (hi < N && (cnt < K || st.find(A[hi]) != st.end())) {
      ans += hi - lo + 1;
      if (st.find(A[hi]) == st.end()) cnt++;
      st.insert(A[hi++]);
    }
    st.erase(st.find(A[lo]));
    if (!st.count(A[lo])) cnt--;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
