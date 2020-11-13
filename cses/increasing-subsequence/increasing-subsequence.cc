/* created   : 2020-11-13 16:30:33
 * accepted  : 2020-11-13 16:49:50
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<int> lis(vector<int>& a) {
  vector<int> ans;
  set<int> st;
  for (int i = 0; i < a.size(); i++) {
    auto it = st.lower_bound(a[i]);
    if (it == st.end()) {
      st.insert(a[i]);
    }
    else {
      st.erase(it);
      st.insert(a[i]);
    }
  }
  return vector<int>(all(st));
}

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  vector<int> ans = lis(A);
  cout << ans.size() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
