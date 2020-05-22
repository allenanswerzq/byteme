/* created   : 2020-05-22 18:01:25
 * accepted  : 2020-05-22 18:34:00
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e4 + 7;
int a[N];
int b[N];

void solve() {
  int n, p, h, m; cin >> n >> p >> h >> m;
  for (int i = 1; i <= n; i++) {
    a[i] = h;
  }
  b[1] = a[1];
  for (int i = 2; i <= n; i++) {
    b[i] = a[i] - a[i - 1];
  }
  set<pair<int, int>> st;
  for (int i = 1; i <= m; i++) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    if (st.count({x, y})) continue;
    st.insert({x, y});
    b[x + 1]--;
    b[y]++;
  }
  for (int i = 2; i <= n; i++) {
    b[i] += b[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
