#include <bits/stdc++.h>
using namespace std;

template <class T>
struct bit {
// Zero index based binary index tree.
  int n;
  vector<T> bt;

  bit(int n_) : n(n_ + 1) {
    bt.resize(n);
  }

  bit(const vector<int>& v) {
    n = v.size() + 1;
    bt.resize(n);
    for (int i = 0; i < n - 1; i++) {
      update(i, v[i]);
    }
  }

  // Adds the val k to the ith position
  void add(int i, int k) {
    for (++i; i < n; i += i & (-i)) {
      bt[i] += k;
    }
  }

  // Returns the sum from index 0 to i
  T query(int i)  {
    T res = 0;
    for (++i; i > 0; i -= i & (-i)) {
      res += bt[i];
    }
    return res;
  }

  // Queries an interval for zero based indeies
  T query(int x, int y) {
    assert(0 <= x && x < n - 1);
    assert(0 <= y && y < n - 1);
    return query(y) - (x - 1 >= 0 ? query(x - 1) : 0);
  }
};

void test() {
  vector<int> v = {1, 2, 3, 4, 5};
  bit<int> bt(v);
  for (int i = 0; i < 5; i++) {
    trace(i, bt.query(i));
    trace(i, bt.query(i, 4));
  }

  bit<int> bt2(5);
  for (int i = 0; i < 5; i++) {
    bt2.add(i, v[i]);
  }
  for (int i = 0; i < 5; i++) {
    trace(bt2.query(i));
  }
}

int main() {
  test();
}
