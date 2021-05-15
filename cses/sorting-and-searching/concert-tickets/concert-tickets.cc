/* created   : 2020-11-05 09:38:40
 * accepted  : 2020-11-05 09:42:13
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, M; cin >> N >> M;
  multiset<int> S;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    S.insert(x);
  }
  for (int i = 0; i < M; i++) {
    int x; cin >> x;
    auto it = S.upper_bound(x);
    if (it != S.begin()) {
      cout << *(--it) << "\n";
      S.erase(it);
    }
    else {
      cout << -1 << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
