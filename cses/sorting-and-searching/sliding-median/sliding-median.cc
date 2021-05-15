/* created   : 2020-11-11 11:18:55
 * accepted  : 2020-11-11 19:56:12
 */
#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long


// clang-format off
template <class T>
using TreeMultiSet = __gnu_pbds::tree<pair<T, int>,
                     __gnu_pbds::null_type, less<pair<T, int>>,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;
// clang-format on

template <class T>
struct OrderedMultiSet : public TreeMultiSet<T> {
  using TreeMultiSet<T>::find_by_order;
  using TreeMultiSet<T>::insert;
  using TreeMultiSet<T>::lower_bound;
  using TreeMultiSet<T>::order_of_key;
  using TreeMultiSet<T>::size;
  using TreeMultiSet<T>::end;

  using iterator = typename TreeMultiSet<T>::iterator;

  int id = 0;

  void insert(T x) { insert(make_pair(x, id++)); }

  T at(int index) {
    assert(0 <= index && index < (int)size());
    return find_by_order(index)->first;
  }

  T operator[](int index) { return at(index); }

  void erase(iterator it) { TreeMultiSet<T>::erase(it); }

  void erase(int index) { erase(find(at(index))); }

  iterator find(T x) {
    size_t p = lower_bound(x);
    if (p < size()) {
      return find_by_order(p);
    } else {
      return end();
    }
  }

  int lower_bound(T x) { return order_of_key({x, 0}); }

  int upper_bound(T x) { return order_of_key({x + 1, 0}); }

  int count(T x) {
    int d = upper_bound(x) - lower_bound(x);
    return d;
  }
};

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  vector<int> ans;
  OrderedMultiSet<int> st;
  for (int i = 0; i < N; i++) {
    st.insert(A[i]);
    if (i >= K - 1) {
      int m = st.size();
      ans.push_back(st[(m - 1) / 2]);
      st.erase(st.find(A[i - K + 1]));
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
