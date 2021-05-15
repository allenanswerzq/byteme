/* created   : 2020-11-06 09:55:02
 * accepted  : 2020-11-06 17:40:21
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
  //       x  x        x
  int X, N; cin >> X >> N;
  set<pair<int, int>> st;
  multiset<int> length;
  st.insert(make_pair(X, 0));
  length.insert(X);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    auto it = st.lower_bound(make_pair(x, -1));
    assert(it != st.end());
    int b = it->second, e = it->first;
    st.erase(it);
    length.erase(length.find(e - b));
    if (x >= b) {
      st.insert(make_pair(x, b));
      length.insert(x - b);
    }
    if (e >= x) {
      st.insert(make_pair(e, x));
      length.insert(e - x);
    }
    trace(st, length, x, b, e);
    if (i > 0) {
      cout << " ";
    }
    cout << *length.rbegin();
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
