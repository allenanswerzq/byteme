/* created   : 2020-04-04 09:31:39
 * accepted  : 2020-04-04 10:13:33
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

struct Node {
  int x, y, id;
};

bool comp(const Node& a, const Node& b) {
  if (a.x == b.x) {
    return a.y < b.y;
  }
  else {
    return a.x < b.x;
  }
}

debugstream& operator<<(debugstream& os, const Node& a) {
  return os << a.x << ' ' << a.y << ' ' << a.id;
}

void solve() {
  int n; cin >> n;
  vector<Node> a;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a.push_back({x, 1, i});
    a.push_back({y, -1, i});
  }
  sort(all(a), comp);
  trace(a);
  bool free_a = true;
  bool free_b = true;
  string ans(n, '#');
  for (int i = 0; i < a.size(); i++) {
    int id = a[i].id;
    if (a[i].y == 1) {
      if (free_a) {
        ans[id] = 'C';
        free_a = false;
      }
      else if (free_b) {
        ans[id] = 'J';
        free_b = false;
      }
      else {
        cout << "IMPOSSIBLE" << '\n';
        return;
      }
    }
    else {
      if (ans[id] == 'C') {
        free_a = true;
      }
      else {
        free_b = true;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
