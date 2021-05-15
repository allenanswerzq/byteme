/* created   : 2021-02-15 16:30:10
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace __gnu_pbds;

template <class T>
using TreeSet = tree<T,
                null_type, less<int>,
                rb_tree_tag,
                tree_order_statistics_node_update>;

void solve() {
  int N; cin >> N;
  TreeSet<int> st;
  for (int i = 1; i <= N; i++) {
    st.insert(i);
  }
  // 1 2 3 4 5 6 7
  int p = 0;
  int step = 1;
  while (st.size()) {
    p = (p + step) % st.size();
    int c = *st.find_by_order(p);
    cout << c << " ";
    st.erase(c);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
