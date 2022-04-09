/* created   : 2020-11-13 13:55:21
 * accepted  : 2020-11-13 14:14:17
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int& x : A) {
    cin >> x;
  }
  // 2 2 4 5
  //
  // f[i][x] = f[i-1][x] | f[i-1][x-c]
  const int INF = 1e5 + 7;
  vector<int> f(INF);
  f[0] = 1;
  for (int i = 0; i < N; i++) {
    for (int x = INF - 1; x >= 0; x--) {
      if (x >= A[i]) {
        f[x] = f[x] | f[x - A[i]];
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i < INF; i++) {
    if (f[i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
