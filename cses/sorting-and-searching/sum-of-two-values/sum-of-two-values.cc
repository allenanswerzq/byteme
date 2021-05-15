/* created   : 2020-11-05 19:07:17
 * accepted  : 2020-11-05 19:19:36
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, X; cin >> N >> X;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    A[i].first = x;
    A[i].second = i;
  }
  sort(all(A));
  int lo = 0, hi = N - 1;
  while (lo < hi) {
    ll sum = A[lo].first + A[hi].first;
    if (sum == X) {
      cout << A[hi].second + 1 << " " << A[lo].second + 1 << "\n";
      return;
    }
    else if (sum > X) {
      hi--;
    }
    else {
      lo++;
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
