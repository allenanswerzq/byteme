/* created   : 2020-11-01 21:22:42
 * accepted  : 2020-11-02 17:19:47
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

vector<string> ans;

void dfs(string& S, int u, string& path, vector<int>& cnt) {
  if (u == S.size()) {
    ans.push_back(path);
    return;
  }
  for (int i = 0; i < S.size(); i++) {
    while (i + 1 < S.size() && S[i] == S[i + 1]) i++;
    int c = S[i] - 'a';
    if (cnt[c]) {
      cnt[c]--;
      path.push_back(S[i]);
      dfs(S, u + 1, path, cnt);
      path.pop_back();
      cnt[c]++;
    }
  }
}

void solve() {
  string S; cin >> S;
  sort(all(S));
  vector<int> cnt(26);
  for (char c : S) cnt[c - 'a']++;
  string path;
  dfs(S, 0, path, cnt);
  assert(path.empty());
  cout << ans.size() << "\n";
  for (auto& s : ans) {
    cout << s << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
