/* created   : 2021-09-11 19:12:24
 * accepted  : 2021-09-11 19:37:55
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  multiset<int> l1;
  multiset<int> free_list;
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    for (int j = 0; j < x; j++) {
      l1.insert(y);
    }
  }
  trace(l1);
  int M; cin >> M;
  vector<int> A(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }
  sort(all(A));
  for (int i = M -1 ; i >= 0; i--) {
    if (free_list.size()) {
      auto it = free_list.lower_bound(A[i]);
      if (it != free_list.end()) {
        int x = *it;
        free_list.erase(it);
        if (x > A[i]) {
          free_list.insert(x - A[i]);
        }
        trace(i, A[i], free_list);
        continue;
      }
    }
    if (l1.size()) {
      auto it = l1.lower_bound(A[i]);
      if (it != l1.end()) {
        int x = *it;
        l1.erase(it);
        if (x > A[i]) {
          free_list.insert(x - A[i]);
        }
        trace(i, A[i], l1);
        continue;
      }
    }
    cout << -1 << "\n";
  }
  ll sum = 0;
  for (auto x : l1) {
    sum += x;
  }
  cout << sum << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
