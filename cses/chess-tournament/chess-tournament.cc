/* created   : 2021-01-18 22:11:09
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  map<pair<int, int>, int> st;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (x > 0) {
      st.insert({{-x, i}, 1});
    }
  }
  trace(st);
  while (st.size()) {
    auto ft = *st.begin();
    int u = ft.first.first, c = ft.first.second;
    if (u > st.size()) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    st.erase(st.begin());
    for (auto& it = st.begin(); it != st.end() && u--; ) {
      cout << c << " " << it->second << "\n";
      if (--(it->first) == 0) {
        it = st.erase(st.begin());
      }
      else {
        it++;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
