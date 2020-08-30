/* created   : 2020-08-30 16:04:28
 * accepted  : 2020-08-30 17:20:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, Q; cin >> N >> Q;
  list<array<int, 3>> D;
  const int INF = 1e9;
  D.push_back({INF, 0, INF});
  D.push_back({INF, 1, 0});
  for (int i = 2; i <= N; i++) {
    int d; cin >> d;
    D.back()[2] = d;
    D.push_back({d, i, 0});
  }
  D.back()[2] = INF;
  D.push_back({INF, N + 1, INF});
  trace(D);
  vector<int> ans;
  for (int i = 1; i <= Q; i++) {
    int S, K; cin >> S >> K;
    auto d_copy = D;
    auto it = d_copy.begin();
    while (S--) it++;
    while (--K) {
      trace(K, d_copy);
      if (it->at(0) < it->at(2)) {
        auto pre = std::prev(it);
        pre->at(2) = it->at(2);
        d_copy.erase(it);
        it = pre;
      }
      else {
        auto nxt = std::next(it);
        nxt->at(0) = it->at(0);
        d_copy.erase(it);
        it = nxt;
      }
    }
    ans.push_back(it->at(1));
  }
  for (int i = 0; i < Q; i++) {
    cout << ans[i] << (i == Q - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
