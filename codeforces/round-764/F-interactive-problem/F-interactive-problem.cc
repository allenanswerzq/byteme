/* created   : 2022-01-15 10:15:52
 * accepted  : 2022-01-15 17:40:46
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  int lo = 0;
  int hi = N;
  int p = 0;
  // (x + c * n - md) / n = c
  // NOTE: binary search on md value, so that the total value
  // added up equals to x
  while (lo + 1 < hi) {
    int md = (lo + hi) / 2;
    // NOTE: if md is negative means that the previous total md
    // value is too big, we need to reduce it
    // N - (-250 + 1000) % N = N - (N - 250) = 250
    cout << "+ " << N - (md + N) % N << endl;
    int d; cin >> d;
    // t += N - (md + N) % N;
    // d = t / N;
    // trace(lo, hi, add, t, d, p);
    if (d > p) {
      // md is too small, so N - md is too big, so we need to
      // try a big md in next turn, but note we need to subtract
      // the md value already added in this trun.
      lo = md;
    }
    else {
      // md is too big.
      hi = md;
    }
    lo -= md;
    hi -= md;
    p = d;
  }
  trace(p, lo, hi);
  cout << "! " << p * N + (lo + N) % N << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // int tc; cin >> tc;
  // for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  // }
  return 0;
}
