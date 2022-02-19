/* created   : 2022-02-18 23:19:48
 * accepted  : 2022-02-19 14:06:05
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<string> A(N);
  unordered_map<string, set<int>> mp;
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    A[i] = s;
    mp[s].insert(i);
  }
  for (int i = 0; i < N; i++) {
    if (A[i].size() == 1) {
      cout << "YES\n";
      return;
    }
  }
  // cases that strings with size equals 1 processed
  //
  // (ab   ba   | (ab,  b, a)   (ab,  cba)
  // (abc, cba) | (abc, c, ba)  (abc, cb, a), (abc, c, b, a)
  //
  trace(A);
  for (int i = 0; i < N; i++) {
    string s = A[i];
    string t = s;
    reverse(all(t));
    if (s == t) {
      cout << "YES\n";
      return;
    }
    for (int j = 0; j <= 28; j++) {
      string x;
      if (j < 26) {
        x = string(1, (char)('a' + j)) + t;
      }
      else if (j == 27) {
        x = t;
      }
      else {
        // abc ba
        x = s.substr(0, s.size() - 1);
        reverse(all(x));
      }
      if (mp.count(x)) {
        int c = *mp[s].begin();
        auto it = mp[x].upper_bound(c);
        if (it != mp[x].end()) {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO" << "\n";
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
