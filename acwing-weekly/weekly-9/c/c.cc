/* created   : 2021-08-08 09:07:51
 * accepted  : 2021-08-08 10:21:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

vector<ll> go(const vector<int>& A) {
  int n = A.size();
  vector<ll> f(n);
  vector<int> stk;
  for (int i = 0; i < n; i++) {
    while (stk.size() && A[stk.back()] >= A[i]) {
      stk.pop_back();
    }
    int p = stk.empty() ? -1 : stk.back();
    f[i] = (p == -1 ? 0 : f[p]) + (i - p) * 1ll * A[i];
    stk.push_back(i);
  }
  return f;
}

void solve() {
  // 1 2 3 4
  // 4 3 2 1
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<ll> f = go(A);
  vector<int> B = A;
  reverse(all(B));
  vector<ll> g = go(B);
  ll sum = 0;
  int pos = -1;
  for (int i = 0; i < N; i++) {
    ll cur = f[i] + g[N - i - 1] - A[i];
    if (sum < cur) {
      sum = cur;
      pos = i;
    }
  }
  assert(pos != -1);
  trace(pos, sum, A);
  trace(f, g);
  vector<int> ans(N);
  ans[pos] = A[pos];
  for (int i = pos - 1; i >= 0; i--) {
    ans[i] = min(A[i], ans[i + 1]);
  }
  for (int i = pos + 1; i < N; i++) {
    ans[i] = min(A[i], ans[i - 1]);
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
