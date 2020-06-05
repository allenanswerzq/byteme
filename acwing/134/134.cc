/* created   : 2020-06-03 22:07:05
 * accepted  : 2020-06-04 11:51:42
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int n;

void solve() {
  unordered_map<int, int> g;
  for (int i = 0; i < n; i++) {
    int m; cin >> m;
    for (int j = 0; j < m; j++) {
      int x; cin >> x;
      g[x] = i;
    }
  }
  list<int> li;
  vector<int> cnt(n);
  unordered_map<int, decltype(li.begin())> mp;
  string op;
  while (cin >> op && op != "STOP") {
    if (op == "ENQUEUE") {
      int x; cin >> x;
      int id = g[x];
      if (mp.count(id)) {
        auto it = li.insert(++mp[id], x);
        mp[id] = it;
        cnt[id]++;
      }
      else {
        li.push_back(x);
        mp[id] = --li.end();
        cnt[id]++;
      }
      // trace(x, g[x], li);
    }
    else if (op == "DEQUEUE") {
      // assert(li.size());
      int x = li.front();
      li.pop_front();
      cout << x << "\n";
      if (--cnt[g[x]] <= 0) {
        mp.erase(g[x]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 0;
  while (cin >> n && n) {
    tc++;
    cout << "Scenario #" << tc << "\n";
    solve();
    cout << "\n";
  }
  return 0;
}
