/* created   : 2020-06-23 07:48:49
 * accepted  : 2020-06-23 08:09:18
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int n;

bool dfs(vector<int>& seq, int depth) {
  if ((int) seq.size() == depth) {
    return seq.back() == n;
  }
  vector<bool> use(200);
  int m = seq.size();
  for (int i = m - 1; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      int add = seq[i] + seq[j];
      if (use[add]) continue;
      if (add > n) continue;
      if (add <= seq.back()) continue;
      use[add] = true;
      seq.push_back(add);
      if (dfs(seq, depth)) return true;
      seq.pop_back();
    }
  }
  return false;
}

void solve() {
  vector<int> seq;
  seq.push_back(1);
  for (int i = 1; i < 100; i++) {
    if (dfs(seq, i)) {
      for (int k = 0; k < seq.size(); k++) {
        cout << seq[k] << (k == seq.size() - 1 ? '\n' : ' ');
      }
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n && n) {
    solve();
  }
  return 0;
}
