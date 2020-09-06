/* created   : 2020-09-06 13:03:42
 * accepted  : 2020-09-06 13:27:50
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

ll square(ll x) { return x * x; }

ll compute(array<ll, 2>& a, array<ll, 2>& b) {
  return square(a[0] - b[0]) + square(a[1] - b[1]);
}

void solve() {
  int N; cin >> N;
  vector<array<ll, 2>> P(2);
  cin >> P[0][0] >> P[0][1] >> P[1][0] >> P[1][1];
  vector<array<ll, 2>> A(N);
  for (auto& a : A) {
    cin >> a[0] >> a[1];
  }
  vector<pair<ll, int>> r1(N);
  for (int i = 0; i < N; i++) {
    r1[i] = {compute(A[i], P[0]), i};
  }
  sort(all(r1));
  // 1). both covers
  ll ans = 1e18;
  for (int i = 0; i < N; i++) {
    ll r2 = 0;
    for (int j = i + 1; j < N; j++) {
      r2 = max(r2, compute(A[r1[j].second], P[1]));
    }
    ans = min(ans, r1[i].first + r2);
  }
  // 2). r1 covers all flowers
  ans = min(ans, r1[N - 1].first);
  // 3). r2 convers all flowers
  ll r2 = 0;
  for (int j = 0; j < N; j++) {
    r2 = max(r2, compute(A[j], P[1]));
  }
  ans = min(ans, r2);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
