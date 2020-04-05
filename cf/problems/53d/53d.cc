/* created   : 2020-04-05 08:45:45
 * accepted  : 2020-04-05 09:19:24
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> v = b;
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == b[j]) {
        for (int k = j; k > i; k--) {
          ans.emplace_back(k, k - 1);
          swap(b[k], b[k - 1]);
        }
        break;
      }
    }
    trace(ans, b);
  }
  // 3 2 1 2
  // 3 1 2 2
  // 1 3 2 2
  trace(b, a, ans);
  assert(ans.size() < (int) 1e6);
  assert(b == a);
  cout << ans.size() << '\n';
  for (auto t : ans) {
    swap(v[t.x], v[t.y]);
  cout << min(t.x, t.y) + 1 << ' ' << max(t.x, t.y) + 1 << '\n';
  }
  trace(v, a);
  assert(v == a);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
