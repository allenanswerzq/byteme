/* created   : 2020-11-05 21:44:06
 * accepted  : 2020-11-05 21:57:58
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  multiset<int> tower;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    auto pt = tower.upper_bound(x);
    if (pt == tower.end()) {
      tower.insert(x);
    }
    else {
      tower.erase(pt);
      tower.insert(x);
    }
  }
  cout << tower.size() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
