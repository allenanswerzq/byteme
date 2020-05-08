/* created   : 2020-05-08 22:08:41
 * accepted  : 2020-05-08 23:00:44
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  trace(n, k, a);
  int x = -1;
  int mi = 1e9 + 7;
  for (int i = 0; i + k < n; i++) {
    int cur = a[i + k] - a[i];
    if (cur < mi) {
      mi = cur;
      x = a[i] + cur / 2;
    }
  }
  cout << x << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
