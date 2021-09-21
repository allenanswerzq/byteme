/* created   : 2021-09-20 21:38:27
 * accepted  : 2021-09-20 22:39:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

ll solution(vector<int>& A, ll X, ll Y) {
  int N = A.size();
  sort(all(A));
  reverse(all(A));
  vector<ll> pre(N + 1);
  for (int i = 0; i < N; i++) {
    pre[i + 1] = pre[i] + A[i];
  }
  auto check = [&](ll md) {
    if (md / X >= N) {
      // Use first can cover all.
      return true;
    }
    ll y = md / Y;
    ll x = (md - y * Y) / X;
    ll have = pre[min(y, (ll)N)] - pre[0];
    // [0....y - 1][0..x-1][....N-1]
    ll need = pre[N] - pre[min(y + x, (ll)N)];
    return have >= need;
  };
  ll lo = -1;
  ll hi = N * X + 1;
  while (lo + 1 < hi) {
    ll md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  return hi;
}

void solve() {
  int N, X, Y; cin >> N >> X >> Y;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cout << solution(A, X, Y) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
