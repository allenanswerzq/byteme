/* created   : 2021-02-17 14:58:47
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace __gnu_pbds;

// clang-format off
template <class T>
using TreeMultiSet = tree<pair<T, int>,
                     null_type, less<pair<T, int>>,
                     rb_tree_tag,
                     tree_order_statistics_node_update>;
// clang-format on

template <class T> struct OrderedMultiSet : public TreeMultiSet<T> {
public:
  using TreeMultiSet<T>::find_by_order;
  using TreeMultiSet<T>::insert;
  using TreeMultiSet<T>::order_of_key;
  using TreeMultiSet<T>::size;
  using TreeMultiSet<T>::end;

  using iterator = typename TreeMultiSet<T>::iterator;

  void insert(T x) { insert(make_pair(x, id_++)); }

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

  int lower_bound(T x) { return order_of_key({x, -1}); }

private:
  size_t id_ = 0;
};

void solve() {
  int N; cin >> N;
  vector<pair<array<int, 2>, int>> A(N);
  for (int i = 0; i < N; i++) {
    auto& a = A[i].first;
    cin >> a[0] >> a[1];
    // NOTE: sort x by increasing, sort y by decreasing order
    a[1] = -a[1];
    A[i].second = i;
  }
  sort(all(A));
  trace(A);
  OrderedMultiSet<int> st;
  vector<int> cc(N);
  for (int i = 0; i < N; i++) {
    auto& a = A[i].first;
    int p = st.lower_bound(-a[1]);
    if (p < st.size()) {
      cc[A[i].second] = st.size() - p;
    }
    st.insert(-a[1]);
  }
  OrderedMultiSet<int> sd;
  vector<int> dd(N);
  for (int i = N - 1; i >= 0; i--) {
    auto& a = A[i].first;
    int p = sd.lower_bound(a[1]);
    if (0 <= p && p < sd.size()) {
      dd[A[i].second] = sd.size() - p;
    }
    sd.insert(a[1]);
  }
  for (int i = 0; i < N; i++) {
    cout << dd[i] << (i == N - 1 ? '\n' : ' ');
  }
  for (int i = 0; i < N; i++) {
    cout << cc[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
