/* created   : 2020-11-08 15:11:19
 * accepted  : 2020-11-08 15:54:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  ll s = 0;
  for (int& a : A) {
    cin >> a;
    s += a;
  }
  sort(all(A));
  cout << max(s, 2ll * A[N - 1]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
