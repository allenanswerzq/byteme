/* created   : 2021-02-15 16:30:10
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  iota(all(A), 1);
  int p = 0;
  int step = 1;
  while (A.size()) {
    p = (p + step) % A.size();
    cout << A[p] << " ";
    A.erase(A.begin() + p);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
