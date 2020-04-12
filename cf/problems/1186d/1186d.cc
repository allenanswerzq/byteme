/* created   : 2020-04-12 11:15:26
 * accepted  : 2020-04-12 11:25:02
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int sign(double x) {
  const double kEPS = 1e-9;
  if (x > kEPS) return 1;
  if (x < -kEPS) return -1;
  return 0;
}

void solve() {
  int n; cin >> n;
  vector<double> a(n);
  vector<int> b(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    double x; cin >> x;
    a[i] = x;
    b[i] = floor(x);
    ans += b[i];
  }
  trace(ans);
  trace(a);
  for (int i = 0; i < n && ans < 0; i++) {
    if (sign(floor(a[i]) - ceil(a[i])) != 0) {
      b[i]++;
      ans++;
    }
  }
  assert(ans == 0);
  for (int i = 0; i < n; i++) {
    cout << b[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
