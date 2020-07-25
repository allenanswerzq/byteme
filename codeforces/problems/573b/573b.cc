/* created   : 2020-05-10 17:56:22
 * accepted  : 2020-05-10 18:34:05
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 7;
int a[N];
int lt[N];
int rt[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  lt[0] = 0;
  for (int i = 1; i <= n; i++) {
    lt[i] = min(lt[i - 1] + 1, a[i]);
  }
  rt[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    rt[i] = min(rt[i + 1] + 1, a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, min(lt[i], rt[i]));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
