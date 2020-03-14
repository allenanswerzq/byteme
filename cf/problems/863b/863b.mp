/* created   : 2020-03-14 21:42:34
 * accepted  : 2020-03-14 21:47:22
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n; cin >> n;
  n *= 2;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1e9 + 7;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<int> b;
      for (int k = 0; k < n; k++) {
        if (k != i && k != j) {
          b.push_back(a[k]);
        }
      }
      do {
        int cur = 0;
        for (int k = 0; k + 1 < (int) b.size(); k += 2) {
          cur += abs(a[k] - a[k + 1]);
        }
        ans = min(ans, cur);
        trace(ans, cur, b);
      } while (next_permutation(all(b)));
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
