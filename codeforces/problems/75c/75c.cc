/* created   : 2020-05-01 09:15:52
 * accepted  : 2020-05-01 09:49:11
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int a, b; cin >> a >> b;
  int g = __gcd(a, b);
  trace(a, b, g);
  set<int> st;
  for (int i = 1; i * i <= g; i++) {
    if (g % i == 0) {
      st.insert(i);
      st.insert(g / i);
    }
  }
  trace(st);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    auto it = st.upper_bound(y);
    if (it == st.begin()) {
      cout << -1 << "\n";
      return;
    }
    it--;
    if (*it >= x) {
      cout << *it << "\n";
    }
    else {
      cout << -1 << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
