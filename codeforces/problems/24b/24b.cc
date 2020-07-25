/* created   : 2020-04-04 20:24:43
 * accepted  : 2020-04-04 21:03:02
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

struct Node {
  int points = 0;
  string name;
  vector<int> wins = vector<int>(54);
};

debugstream& operator<<(debugstream& os, Node& a) {
  return os << a.name << ' ' << a.points << ' ' << a.wins;
}

int points[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

void solve() {
  int n; cin >> n;
  map<string, int> mp;
  vector<Node> a;
  for (int i = 0; i < n; i++) {
    int m; cin >> m;
    for (int j = 0; j < m; j++) {
      string x; cin >> x;
      if (!mp.count(x)) {
        mp[x] = a.size();
        Node node;
        node.name = x;
        node.points += (j < 10 ? points[j] : 0);
        node.wins[j]++;
        a.push_back(node);
      }
      else {
        Node& node = a[mp[x]];
        node.points += (j < 10 ? points[j] : 0);
        node.wins[j]++;
      }
    }
  }
  vector<Node> b = a;
  sort(all(a), [](Node& x, Node& y) {
    if (x.points == y.points) {
      return x.wins > y.wins;
    }
    else {
      return x.points > y.points;
    }
  });
  trace(a);
  sort(all(b), [](Node& x, Node& y) {
    if (x.wins[0] == y.wins[0]) {
      if (x.points == y.points) {
        return x.wins > y.wins;
      }
      else {
        return x.points > y.points;
      }
    }
    else {
      return x.wins[0] > y.wins[0];
    }
  });
  cout << a[0].name << '\n';
  cout << b[0].name << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
