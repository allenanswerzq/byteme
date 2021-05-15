/* created   : 2020-11-13 20:13:02
 * accepted  : 2020-11-14 10:00:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<array<int, 3>> A(N);
  for (int i = 0; i < N; i++) {
    int b, e, w; cin >> b >> e >> w;
    A[i] = {e, b, w};
  }
  sort(all(A));
  trace(A);
  // 2 3 4 5 6 7 8
  // [-4-]
  //   [--6--]
  //       [-3-]
  //         [-2-]
  // f[i] = max(w) + f[j] end_j < start_i
  // const int INF = 1e9 + 7;
  multiset<array<ll, 2>> st;
  ll cur = 0;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    int b = A[i][1], e = A[i][0], w = A[i][2];
    trace(i, b, st);
    // --]
    //  ---]
    //    ---]
    //       [b ---- e]
    auto it = st.upper_bound({b, -1});
    if (it != st.begin()) {
      --it;
      cur = (*it)[1] + w;
    }
    else {
      cur = w;
    }
    ans = max(ans, cur);
    st.insert({e, ans});
    trace(i, cur, ans, st);
  }
  cout << ans << "\n";
}

void solve_bruteforce() {
  int N; cin >> N;
  vector<array<int, 3>> A(N);
  for (int i = 0; i < N; i++) {
    int b, e, w; cin >> b >> e >> w;
    A[i] = {e, b, w};
  }
  sort(all(A));
  vector<ll> f(N);
  for (int i = 0; i < N; i++) {
    f[i] = A[i][2];
  }
  // f[i] = max(w) + f[j] end_j < start_i
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (A[j][0] < A[i][1]) {
        f[i] = max(f[i], f[j] + A[i][2]);
      }
    }
  }
  cout << *max_element(all(f)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
