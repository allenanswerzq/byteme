/* created   : 2022-01-12 23:11:34
 * accepted  : 2022-01-15 10:06:19
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 3>;

void solve() {
  int N, M; cin >> N >> M;
  map<string, ar> mp;
  for (int i = 0; i < N; i++) {
    string x; cin >> x;
    // At any position, there are only two possiable to consider,
    // either starts with length 2 or 3
    // 4 = 2 + 2
    // 5 = 2 + 3 or 3 + 2
    for (int j = 0; j + 1 < x.size(); j++) {
      mp[x.substr(j, 2)] = {j + 1, j + 2, i + 1};
    }
    for (int j = 0; j + 2 < x.size(); j++) {
      mp[x.substr(j, 3)] = {j + 1, j + 3, i + 1};
    }
  }
  trace(mp);
  string S; cin >> S;
  vector<int> f(M + 1);
  f[0] = 1;
  for (int i = 1; i <= M; i++) {
    if (i + 1 <= M && f[i - 1] && mp.count(S.substr(i - 1, 2))) {
      f[i + 1] |= 1;
    }
    if (i + 2 <= M && f[i - 1] && mp.count(S.substr(i - 1, 3))) {
      f[i + 2] |= 2;
    }
  }
  trace(f);
  if (f[M] == 0) {
    cout << -1 << "\n";
    return;
  }
  vector<ar> ans;
  for (int i = M; i > 1; ) {
    if (f[i] == 1 || f[i] == 3) {
      string x = S.substr(i - 2, 2);
      assert(mp.count(x));
      ans.push_back(mp[x]);
      i -= 2;
    }
    else if (f[i] == 2) {
      string x = S.substr(i - 3, 3);
      assert(mp.count(x));
      ans.push_back(mp[x]);
      i -= 3;
    }
    else {
      assert(false);
    }
  }
  cout << ans.size() << "\n";
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
