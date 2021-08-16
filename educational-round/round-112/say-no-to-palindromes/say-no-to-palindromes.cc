/* created   : 2021-08-14 09:37:08
 * accepted  : 2021-08-14 11:20:46
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void dfs(int i, int n, string& s) {
  if (i == n) {
    // trace(s);
    bool ok = true;
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n;  k++) {
        string t = s.substr(j, k - j + 1);
        string r = t;
        reverse(all(r));
        if (r == t) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      trace(s);
    }
    return;
  }
  for (int j = 0; j < 3; j++) {
    s.push_back((char)('a' + j));
    dfs(i + 1, n, s);
    s.pop_back();
  }
}

void solve() {
  int N, M; cin >> N >> M;
  string S; cin >> S;
  vector<vector<int>> pr(6, vector<int>(N + 1));
  vector<int> p = {0, 1, 2};
  for (int i = 0; i < 6; i++) {
    trace(i, p);
    for (int j = 0; j < N; j++) {
      char c = (char)(p[j % 3] + 'a');
      pr[i][j + 1] = pr[i][j] + (c != S[j]);
    }
    next_permutation(all(p));
  }
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    a--;
    int ans = 2e9;
    for (int j = 0; j < 6; j++) {
      ans = min(ans, pr[j][b] - pr[j][a]);
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
