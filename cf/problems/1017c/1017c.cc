/* created   : 2020-05-04 15:04:33
 * accepted  : 2020-05-04 16:02:13
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  int x = (int) sqrt(n);
  vector<int> a(n + 1);
  int t = n;
  for (int i = 1; i <= n; i += x) {
    for (int j = min(i + x - 1, n); j >= i; j--) {
      a[j] = t--;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
