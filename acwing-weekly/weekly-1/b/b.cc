/* created   : 2021-07-25 21:41:00
 * accepted  : 2021-07-25 22:40:43
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  sort(all(A));
  int lo = 0;
  int hi = 2e9 + 1;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    ll cnt = 0;
    for (int i = N / 2; i < N; i++) {
      if (A[i] < md) {
        cnt += md - A[i];
      }
    }
    if (cnt <= K) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  cout << lo << "\n";
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
