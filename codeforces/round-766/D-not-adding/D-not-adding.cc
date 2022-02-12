/* created   : 2022-02-12 09:35:25
 * accepted  : 2022-02-12 17:18:38
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  unordered_set<int> A;
  int mx = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    A.insert(x);
    mx = max(x, mx);
  }
  int cnt = 0;
  for (int i = 1; i <= mx; i++) {
    // Check whether i exists in the final array.
    if (A.count(i)) {
      cnt++;
    }
    else {
      vector<int> g;
      for (int c = 2; c * i <= mx; c++) {
        if (A.count(c * i)) {
          g.push_back(c * i);
        }
      }
      if (g.size() <= 1) continue;
      int t = __gcd(g[0], g[1]);
      for (int j = 2; j < g.size(); j++) {
        t = __gcd(t, g[j]);
      }
      trace(i, g, t);
      if (t == i) {
        cnt++;
      }
    }
  }
  cout << cnt - N << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
