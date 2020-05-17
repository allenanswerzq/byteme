/* created   : 2020-05-17 10:25:00
 * accepted  : 2020-05-17 17:00:40
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

#define TreeSet tree<               \
  T, null_type, less<int>,          \
  rb_tree_tag,                      \
  tree_order_statistics_node_update>

template <class T>
struct OrderedSet : public TreeSet {
  using TreeSet::find_by_order;
  using TreeSet::order_of_key;
  using TreeSet::size;
  using TreeSet::find;
  using TreeSet::end;
  using TreeSet::begin;
  using TreeSet::insert;

  // Returns the `ith` element in a set zero index based.
  T at(int index) {
    assert(0 <= index && index < (int) size());
    return *find_by_order(index);
  }

  T operator[](int index) {
    return at(index);
  }

  // Returns the index of a value.
  int index(T val) {
    if (find(val) == end()) {
      return -1;
    }
    return order_of_key(val);
  }

  int count(T x) {
    return (find(x) == end() ? 0 : 1);
  }
};

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    a[i] = {-b[i], i};
  }
  sort(all(a));
  int q; cin >> q;
  vector<array<int, 3>> queries(q);
  for (int i = 0; i < q; i++) {
    int k, p; cin >> k >> p;
    queries[i] = {k, p, i};
  }
  sort(all(queries));
  vector<int> ans(q);
  OrderedSet<int> st;
  trace(a);
  int lo = 0;
  for (auto ar : queries) {
    int k = ar[0];
    int p = ar[1];
    int i = ar[2];
    while ((int) st.size() < k) {
      st.insert(a[lo++].y);
    }
    ans[i] = b[st[p - 1]];
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
