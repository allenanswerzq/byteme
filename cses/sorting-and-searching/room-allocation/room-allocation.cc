/* created   : 2020-11-07 09:41:46
 * accepted  : 2020-11-07 10:50:05
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<pair<array<int, 2>, int>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first[0];
    cin >> A[i].first[1];
    A[i].second = i;
  }
  sort(all(A));
  set<pair<int, int>> room;
  int ans = 0;
  int cnt = 1;
  vector<int> assign(N);
  for (int i = 0; i < N; i++) {
    int b = A[i].first[0], e = A[i].first[1], idx = A[i].second;
    auto it = room.upper_bound(make_pair(b, -1));
    // room: ...(b, 3)
    if (it == room.begin()) {
      room.insert(make_pair(e, cnt));
      assign[idx] = cnt++;
    }
    else {
      pair<int, int> p = *room.begin();
      // NOTE: modify set or map == erase then insert.
      room.erase(room.begin());
      p.first = e;
      room.insert(p);
      assign[idx] = p.second;
    }
    ans = max(ans, (int)room.size());
  }
  cout << ans << "\n";
  for (int i = 0; i < N; i++) {
    cout << assign[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
