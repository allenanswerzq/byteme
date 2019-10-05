/* created   : 2019-08-25 14:28:19
 * accepted  : 2019-08-25 15:42:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve(int tc) {
  cout << "Case #" << tc << ": ";
  int a, b; cin >> a >> b;
  int ans = 0;
  for (int x = a; x <= b; x++) {
    set<int> fact;
    fact.insert(1);
    fact.insert(x);
    int t = x;
    for (int i = 2; i * i <= x; i++) {
      if (t % i == 0) {
        fact.insert(i);
        while (t % i == 0) {
          t /= i;
        }
      }
    }
    if (t > 1) {
      fact.insert(t);
    }
    vector<int> tt(fact.begin(), fact.end());
    int n = tt.size();
    vector<int> all;
    for (int j = 0; j < (1 << n); j++) {
      int y = 1;
      for (int k = 0; k < 32; k++) {
        if ((1 << k) & j) {
          y *= tt[j];
        }
      }

    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }
  return 0;
}
