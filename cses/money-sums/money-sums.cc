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
  for (int& a : A) {
    cin >> a;
  }
  sort(all(A));
  trace(A);
  const int INF = 1e5;
  // f[i][x] = f[i - 1][x] | f[i - 1][x - ai]
  vector<bool> f(INF);
  f[0] = 1;
  for (int a : A) {
    vector<bool> p = f;
    for (int i = 1; i < INF; i++) {
      p[i] = f[i];
      if (i - a >= 0) {
        p[i] = p[i] | f[i - a];
      }
    }
    swap(f, p);
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
