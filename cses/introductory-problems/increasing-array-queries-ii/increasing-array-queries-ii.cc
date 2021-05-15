/* created   : 2021-03-13 18:15:08
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

// NOTE: same problem but solve different apporach.

void solve() {
  int N, Q; cin >> N >> Q;
  vector<ll> A(N);
  vector<ll> pre(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    pre[i] = (i ? pre[i - 1] : 0) + A[i];
  }
  // Rembemers the 1, 2, 4, 8, 16th.. greater postions
  vector<vector<int>> nxt(N, vector<int>(21, N + 1));
  vector<vector<ll>> val(N, vector<ll>(21, 0));
  vector<int> stk;
  for (int i = 0; i < N; i++) {
    while (stk.size() && A[i] > A[stk.back()]) {
      int p = stk.back();
      nxt[p][0] = i;
      // Compute the values in interval [p + 1, i)
      val[p][0] = A[p] * (i - p - 1) - (pre[i - 1] - pre[p]);
      stk.pop_back();
    }
    stk.push_back(i);
  }
  // Binary lifting
  for (int j = 1; j <= 20; j++) {
    for (int i = 0; i < N; i++) {
      int p = nxt[i][j - 1];
      if (p < N) {nxt[i][j] = nxt[p][j - 1];
        val[i][j] = val[i][j - 1] + val[p][j - 1];
      }
    }
  }
  for (int q = 0; q < Q; q++) {
    int l, r; cin >> l >> r; l--, r--;
    int pos = l;
    ll ans = 0;
    for (int i = 20; i >= 0; i--) {
      if (nxt[pos][i] <= r) {
        ans += val[pos][i];
        pos = nxt[pos][i];
      }
    }
    ans += A[pos] * (r - pos) - (pre[r] - pre[pos]);
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
