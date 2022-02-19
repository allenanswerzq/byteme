/* created   : 2021-10-24 13:17:49
 * accepted  : 2021-10-24 13:43:17
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> U(N);
  for (int i = 0; i < N; i++) {
    cin >> U[i];
  }
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < N; i++) {
    int c; cin >> c;
    mp[U[i]].push_back(c);
  }
  unordered_map<int, vector<ll>> pre;
  for (auto & it : mp) {
    auto v = it.second;
    sort(all(v));
    reverse(all(v));
    vector<ll> tmp(v.size() + 1);
    for (int i = 0; i < v.size(); i++) {
      tmp[i + 1] = tmp[i] + v[i];
    }
    pre[it.first] = tmp;
  }
  vector<ll> ans(N + 1);
  for (auto it : pre) {
    auto v = it.second;
    int m = v.size() - 1;
    for (int k = 1; k <= m; k++) {
      int p = m / k * k;
      // trace(v, k, p);
      assert(p < v.size());
      ans[k] += v[p];
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << (i == N ? '\n' : ' ');
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
