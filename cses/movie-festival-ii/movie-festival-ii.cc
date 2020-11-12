/* created   : 2020-11-12 09:21:48
 * accepted  : 2020-11-12 10:04:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  //   [-----]
  //     [-----]
  // [-------]
  // 1 2 3 4 5 6 7 8 9 10
  //               [----]
  //           [-----]
  int N, K; cin >> N >> K;
  vector<array<int, 2>> A(N);
  for (auto& a : A) {
    cin >> a[1] >> a[0];
  }
  // sort by ending time
  sort(all(A));
  int ans = 0;
  // Remember the ending time of a movie for every person.
  multiset<int> watched;
  // [----]
  //    [-----]
  //        [-------]   [------] (i)
  //          [--------------------------] (i + 1)
  for (int i = 0; i < N; i++) {
    int b = A[i][1], e = A[i][0];
    // Find the latest person to assign this movie to
    auto it = watched.upper_bound(b);
    if (it != watched.begin()) {
      int t = *(--it);
      watched.erase(watched.find(t));
      watched.insert(e);
      ans++;
    }
    else if (watched.size() < K) {
      watched.insert(e);
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
