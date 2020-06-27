/* created   : 2020-06-27 09:49:16
 * accepted  : 2020-06-27 11:37:28
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 320;
vector<array<int, 3>> routes;
int arrive[N];
int n;

bool check(int a, int d) {
  // This specific route passed this stop at different time.
  for (int t = a; t < 60; t += d) {
    if (arrive[t] == 0) {
      return false;
    }
  }
  return true;
}

bool dfs(int depth, int u, int covered) {
  if (depth == 0) {
    // All arrive times are been covered.
    return covered == n;
  }
  for (int i = u; i < routes.size(); i++) {
    int cnt = routes[i][0];
    int a = routes[i][1];
    int d = routes[i][2];
    if (cnt * depth + covered < n) continue;
    if (check(a, d) == false) continue;
    for (int t = a; t < 60; t += d) {
      arrive[t]--;
    }
    if (dfs(depth - 1, i, covered + cnt)) return true;
    for (int t = a; t < 60; t += d) {
      arrive[t]++;
    }
  }
  return false;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    arrive[t]++;
  }
  for (int a = 0; a < 60; a++) {
    for (int d = a + 1; a + d < 60; d++) {
      if (check(a, d)) {
        routes.push_back({(59 - a) / d + 1, a, d});
      }
    }
  }
  sort(all(routes));
  reverse(all(routes));
  trace(n, routes.size());
  int depth = 0;
  while (dbg(!dfs(depth, 0, 0))) {
    depth++;
  }
  cout << depth << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
