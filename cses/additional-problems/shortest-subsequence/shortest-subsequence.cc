/* created   : 2021-01-04 23:19:29
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  string S; cin >> S;
  int n = S.size();
  string ans;
  set<char> st;
  for (int i = 0; i < n; i++) {
    st.insert(S[i]);
    if (st.size() == 4) {
      ans.push_back(S[i]);
      st.clear();
    }
  }
  if (st.empty()) {
    ans.push_back('A');
  }
  else {
    for (char c : {'A', 'G', 'C', 'T'}) {
      if (!st.count(c)) {
        ans.push_back(c);
        break;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
