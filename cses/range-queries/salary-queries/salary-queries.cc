/* created   : 2020-11-28 20:57:17
 * accepted  : 2020-11-28 22:01:39
 */
#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <class T>
using TreeSet = __gnu_pbds::tree<T,
                __gnu_pbds::null_type, less<T>,
                __gnu_pbds::rb_tree_tag,
                __gnu_pbds::tree_order_statistics_node_update>;

void solve() {
  int N, Q; cin >> N >> Q;
  TreeSet<array<int, 2>> st;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    A[i] = x;
    st.insert({x, i});
  }
  trace(st);
  for (int i = 0; i < Q; i++) {
    char op; cin >> op;
    if (op == '!') {
      int k, x; cin >> k >> x;
      k--;
      st.erase({A[k], k});
      A[k] = x;
      st.insert({x, k});
    }
    else {
      int a, b; cin >> a >> b;
      int x = st.order_of_key({a, 0});
      int y = st.order_of_key({b + 1, 0});
      cout << y - x << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
