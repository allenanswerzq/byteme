/* created   : 2021-11-13 15:21:57
 * accepted  : 2021-11-13 16:04:24
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int A, B, C; cin >> A >> B >> C;
  A--, B--, C--;
  string c = "1";
  string a = "1";
  string b = "1";
  c = c + string(C, '0');
  a = a + string(A - C, '0') + string(C, '0');
  b = b + string(B - C, '1') + string(C, '0');
  cout << a << " " << b << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
