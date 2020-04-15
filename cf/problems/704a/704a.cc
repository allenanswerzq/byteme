/* created   : 2020-04-15 07:35:12
 * accepted  : 2020-04-15 08:41:04
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, q; cin >> n >> q;
  set<int> notifs;
  vector<vector<int>> app(n);
  int k = 0;
  for (int i = 0; i < q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int x; cin >> x;
      x--;
      app[x].push_back(k);
      notifs.insert(k);
      k++;
    }
    else if (op == 2) {
      int x; cin >> x;
      x--;
      for (auto it : app[x]) {
        notifs.erase(it);
      }
      app[x].clear()
    }
    else {
      int t; cin >> t;
      t--;
      while (!notifs.empty()) {
        auto it = notifs.begin();
        if (*it > t) {
          break;
        }
        notifs.erase(it);
      }
    }
    cout << notifs.size() << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
