/* created   : 2019-11-17 13:01:48
 * accepted  : 2019-11-17 13:19:56
 * author    : landcold7
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define RB rb_tree_tag, tree_order_statistics_node_update
#define OD_MAP tree<X, Y, less<int>, RB>
#define OD_SET tree<T, null_type, less<int>, RB>
#define OD_MSET tree<pair<T, int>, null_type, less<pair<T, int>>, RB>
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

template<class T>
struct ordered_multiset : public OD_MSET {
  using OD_MSET::find_by_order;
  using OD_MSET::insert;
  using OD_MSET::lower_bound;
  using OD_MSET::order_of_key;
  using OD_MSET::size;

  typedef typename OD_MSET::iterator iterator;
  typedef typename OD_MSET::const_iterator const_iterator;

  int id = 0;

  void insert(T x) {
    insert({x, id++});
  }

  T at(int index) {
    assert(0 <= index && index < (int) size());
    return find_by_order(index)->first;
  }

  // Get the `index`th element.
  const_iterator att(int index) const {
    assert(0 <= index && index < (int) size());
    return find_by_order(index);
  }

  iterator att(int index) {
    assert(0 <= index && index < (int) size());
    return find_by_order(index);
  }

  // Get the index of a specific key `x`.
  int index(int x) {
    return order_of_key({x, 0});
  }

  void erase(iterator it) {
    OD_MSET::erase(it);
  }

  void erase(int index) {
    erase(att(index));
  }

  // O(logc + count(x))
  void erase_all(T x) {
    int lo = lower_bound(x);
    int hi = upper_bound(x);
    int cnt = hi - lo;
    for (int i = 0; i < cnt; i++) {
      erase(lo);
    }
  }

  int lower_bound(T x) {
    return order_of_key({x, 0});
  }

  int upper_bound(T x) {
    return order_of_key({x + 1, 0});
  }

  int count(T x) {
    int d = upper_bound(x) - lower_bound(x);
    assert(d >= 1);
    return d;
  }
};

bool check(ordered_multiset<int>& st, int md) {
  // trace(st, md);
  int x = st.lower_bound(md);
  int n = st.size();
  if (n - x >= md) {
    return true;
  }
  return false;
}

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  ordered_multiset<int> st;
  for (int i = 0; i < n; i++) {
    st.insert(v[i]);
    int lo = 1;
    int hi = st.size();
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      if (check(st, md)) {
        lo = md;
      }
      else {
        hi = md;
      }
    }
    cout << (check(st, hi) ? hi : lo) << (i == n - 1 ? '\n' : ' ');;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
