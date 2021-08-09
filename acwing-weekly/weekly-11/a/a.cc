/* created   : 2021-08-09 22:12:21
 * accepted  : 2021-08-09 22:19:51
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  vector<int> A(4);
  for (int i = 0; i < 4; i++) {
    cin >> A[i];
  }
  sort(all(A));
  int t = A[3];
  vector<int> a(3);
  a[0] = A[0] + A[1] - t;
  a[1] = A[0] + A[2] - t;
  a[2] = A[1] + A[2] - t;
  sort(all(a));
  cout << a[0] << " " << a[1] << " " << a[2] << "\n";
  // a + (a + b + c) = (a + b) + (a + c)
  // a + b =
  // a + c =
  // b + c =
  // a + b + c = x
  // a <= b <= c
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
