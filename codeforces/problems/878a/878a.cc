/* created   : 2020-05-13 22:27:28
 * accepted  : 2020-05-13 23:12:09
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> v(10, -1);
  for (int i = 0; i < n; i++) {
    char ch; int x;
    cin >> ch >> x;
    if (ch == '|') {
      for (int j = 0; j < 10; j++) {
        if (x & (1 << j)) {
          v[j] = 1;
        }
      }
    }
    else if (ch == '&') {
      for (int j = 0; j < 10; j++) {
        if (!(x & (1 << j))) {
          v[j] = 0;
        }
      }
    }
    else {
      // 1-1=0
      // 0-1=1
      // 1-0=1
      // 0-0=0
      for (int j = 0; j < 10; j++) {
        if (x & (1 << j)) {
          v[j] ^= 1;
        }
      }
    }
  }
  trace(v);
  int a = 0;
  int b = 0;
  int c = 0;
  for (int i = 0; i < 10; i++) {
    if (v[i] == 1) {
      a |= (1 << i);
    }
    else if (v[i] == 0) {
      b |= (1 << i);
    }
    else if (v[i] == -2) {
      c |= (1 << i);
    }
  }
  int ans = (a > 0) + (b > 0) + (c > 0);
  cout << ans << "\n";
  if (ans > 0) {
    if (a > 0) cout << "| " << a << "\n";
    if (b > 0) cout << "& " << 1023 - b << "\n";
    if (c > 0) cout << "^ " << c << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
