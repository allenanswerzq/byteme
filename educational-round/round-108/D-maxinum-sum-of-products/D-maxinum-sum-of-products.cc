/* created   : 2021-10-24 15:19:11
 * accepted  : 2021-10-24 16:07:46
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<ll> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  vector<ll> pre(N + 1);
  for (int i = 0; i < N; i++) {
    pre[i + 1] = pre[i] + A[i] * B[i];
  }
  ll ans = pre[N];
  for (int i = 0; i < N; ++i) {
    ll cur = A[i] * B[i];
    for (int len = 1; len <= min(i, N - i - 1); len++) {
      int l = i - len;
      int r = i + len;
      trace(len, i, l, r);
      // [l...r]
      cur += A[l] * B[r];
      cur += A[r] * B[l];
      ans = max(ans, cur + /*[0,l)*/pre[l] + /*(r,N-1]*/pre[N] - pre[r + 1]);
    }
    cur = 0;
    for (int len = 1; len <= min(i, N - i); len++) {
      // Note: for even spliting, i as the first right side position.
      // 0123|i___
      int l = i - len;
      int r = i + len - 1;
      cur += A[l] * B[r];
      cur += A[r] * B[l];
      ans = max(ans, cur + /*[0,l)*/pre[l] + /*(r,N-1]*/pre[N] - pre[r + 1]);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
