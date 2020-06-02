/* created   : 2020-06-02 06:45:45
 * accepted  : 2020-06-02 07:20:46
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

void solve() {
  int n, m; cin >> n >> m;
  vector<pii> machines(n);
  for (int i = 0; i < n; i++) {
    cin >> machines[i].x >> machines[i].y;
  }
  vector<pii> tasks(m);
  for (int i = 0; i < m; i++) {
    cin >> tasks[i].x >> tasks[i].y;
  }
  sort(all(tasks));
  sort(all(machines));
  int ans = 0;
  ll gain = 0;
  multiset<int> st;
  for (int i = m - 1, j = n - 1; i >= 0; i--) {
    int x = tasks[i].x;
    int y = tasks[i].y;
    while (j >= 0 && machines[j].x >= x) {
      st.insert(machines[j--].y);
    }
    auto it = st.lower_bound(y);
    if (it != st.end()) {
      ans++;
      gain += 500 * x + 2 * y;
      st.erase(it);
    }
  }
  cout << ans << " " << gain << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
