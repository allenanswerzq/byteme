/* created   : 2020-11-04 22:05:54
 * accepted  : 2020-11-04 22:26:12
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, X; cin >> N >> X;
  multiset<int> S;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    S.insert(x);
  }
  int ans = 0;
  while (S.size()) {
    int b = *S.begin();
    S.erase(S.begin());
    // b + t <= X
    // t <= X - b
    auto it = S.upper_bound(X - b);
    if (it != S.begin()) {
      S.erase(--it);
    }
    ans++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
