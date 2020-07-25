/* created   : 2020-05-06 23:20:07
 * accepted  : 2020-05-07 23:01:32
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  multiset<int> st;
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    trace(i, st, ans);
    string op; cin >> op;
    if (op == "insert") {
      int x; cin >> x;
      st.insert(x);
      ans.push_back({0, x});
    }
    else if (op == "getMin") {
      int x; cin >> x;
      while (!st.empty() && x > *st.begin()) {
        st.erase(st.begin());
        ans.push_back({2, -1});
      }
      if (st.empty() || *st.begin() != x) {
        st.insert(x);
        ans.push_back({0, x});
      }
      ans.push_back({1, x});
    }
    else {
      if (st.empty()) {
        st.insert(2);
        ans.push_back({0, 2});
        st.erase(st.begin());
        ans.push_back({2, -1});
      }
      else {
        st.erase(st.begin());
        ans.push_back({2, -1});
      }
    }
    trace(ans);
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < (int) ans.size(); i++) {
    if (ans[i].x == 0) {
      cout << "insert " << ans[i].y << "\n";
    }
    else if (ans[i].x == 1) {
      cout << "getMin " << ans[i].y << "\n";
    }
    else {
      cout << "removeMin" << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
