/* created   : 2020-03-14 22:17:02
 * accepted  : 2020-03-14 22:38:24
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
  int n, m; cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].x >> a[i].y;
  }
  set<int> st;
  for (int i = 1; i <= 1000; i++) {
    int j = 0;
    for (; j < m; j++) {
      if ((a[j].x + i - 1) / i != a[j].y) {
        break;
      }
    }
    if (j == m) {
      trace(i, j);
      st.insert((n + i - 1) / i);
    }
  }
  cout << ((int) st.size() == 1 ? *st.begin() : -1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
