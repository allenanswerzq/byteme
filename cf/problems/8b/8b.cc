/* created   : 2020-03-22 10:43:31
 * accepted  : 2020-03-22 11:36:58
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

struct Node {
  int x, y, h;
};

debugstream& operator<<(debugstream& os, Node& a) {
  return os << a.x << ' ' << a.y << ' ' << a.h;
}

int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};

void solve() {
  string s; cin >> s;
  set<pii> st;
  int n = s.size();
  int x = 0, y = 0;
  st.insert({x, y});
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') {
      y++;
    }
    else if (s[i] == 'R') {
      y--;
    }
    else if (s[i] == 'U') {
      x++;
    }
    else {
      x--;
    }
    // trace(x, y);
    st.insert({x, y});
  }
  trace(x, y);
  deque<Node> dq;
  set<pii> use;
  use.insert({0, 0});
  dq.push_back({0, 0, 0});
  while (!dq.empty()) {
    auto node = dq.front();
    dq.pop_front();
    if (node.x == x && node.y == y) {
      if (node.h != n) {
        cout << "BUG" << '\n';
        return;
      }
    }
    for (int i = 0; i < 4; i++) {
      int nx = node.x + dx[i];
      int ny = node.y + dy[i];
      if (!use.count({nx, ny}) && st.count({nx, ny})) {
        use.insert({nx, ny});
        dq.push_back({nx, ny, node.h + 1});
      }
    }
  }
  cout << "OK" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
