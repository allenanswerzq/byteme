/* created   : 2020-11-02 22:25:21
 * accepted  : 2020-11-03 21:24:07
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> ch = {'U', 'D', 'L', 'R'};
vector<string> A;
int ans = 0;

void dfs(string& S, string path, int x, int y) {
  trace(S, path, x, y, ans);
  if (path.size() > S.size()) {
    return;
  }
  if (x == 6 && y == 0) {
    if (path.size() == S.size()) ans++;
    return;
  }
  A[x][y] = '@';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    int n = path.size();
    if (!(0 <= nx && nx < 7)) continue;
    if (!(0 <= ny && ny < 7)) continue;
    if (A[nx][ny] != '.') continue;
    if (S[n] == '?' || S[n] == ch[i]) {
      path.push_back(ch[i]);
      dfs(S, path, nx, ny);
      path.pop_back();
    }
  }
  A[x][y] = '.';
}

void solve() {
  string S; cin >> S;
  A.resize(7, string(7, '.'));
  string path;
  dfs(S, path, 0, 0);
  assert(path.empty());
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
