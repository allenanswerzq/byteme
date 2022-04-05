/* created   : 2021-02-16 16:32:54
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  // |-------------------|
  //  |----------------------|
  //    |-------|
  //    |-----|
  //     |-------|
  //      |------|
  int N; cin >> N;
  vector<pair<array<int, 2>, int>> A(N);
  for (int i = 0; i < N; i++) {
    auto& a = A[i].first;
    cin >> a[0] >> a[1];
    // NOTE: sort x by increasing, sort y by decreasing order
    a[1] = -a[1];
    A[i].second = i;
  }
  sort(all(A));
  // trace(A);

  vector<int> cc(N);
  set<int> st;
  for (int i = 0; i < N; i++) {
    auto& a = A[i].first;
    auto it = st.lower_bound(-a[1]);
    if (it != st.end()) {
      // This range is contained by other ranges.
      cc[A[i].second] = 1;
    }
    st.insert(-a[1]);
  }

  vector<int> dd(N);
  set<int> sd;
  for (int i = N - 1; i >= 0; i--) {
    auto& a = A[i].first;
    auto it = sd.lower_bound(a[1]);
    if (it != sd.end()) {
      // This range contains other ranges.
      dd[A[i].second] = 1;
    }
    sd.insert(a[1]);
  }

  for (int i = 0; i < N; i++) {
    cout << dd[i] << (i == N - 1 ? '\n' : ' ');
  }
  for (int i = 0; i < N; i++) {
    cout << cc[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
