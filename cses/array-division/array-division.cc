/* created   : 2020-11-10 09:22:49
 * accepted  : 2020-11-12 08:39:41
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  ll lo = 1;
  ll hi = 1e18 + 7;
  while (lo + 1 < hi) {
    ll md = lo + (hi - lo) / 2;
    int cnt = 1;
    ll cur = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] > md) {
        cnt = K + 1;
        break;
      }
      if (cur + A[i] <= md) {
        cur += A[i];
      }
      else {
        cnt++;
        cur = A[i];
      }
    }
    if (cnt <= K) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
