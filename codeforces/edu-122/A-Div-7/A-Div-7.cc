/* created   : 2022-03-06 23:09:01
 * accepted  : 2022-03-06 23:22:08
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

vector<int> st;

void solve() {
  int N; cin >> N;
  pair<int, int> ans = {10, 0};
  string a = to_string(N);
  for (int c : st) {
    string s = to_string(c);
    if (s.size() != a.size()) continue;
    int d = 0;
    for (int j = 0; j < a.size(); j++) {
      d += (s[j] != a[j]);
    }
    if (d < ans.first) {
      ans = {d, c};
    }
  }
  cout << ans.second << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  for (int i = 1; i * 7 < 1000; i++) {
    st.push_back(i * 7);
  }
  trace(st);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
