/* created   : 2020-04-23 23:47:41
 * accepted  : 2020-04-23 23:47:41
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

class Segtree {
  int n;
  vector<int> tree;

  Segtree(int n_) {
    n = n_;
    tree.resize(2 * n);
  }

  template <class T>
  Segtree(const vector<T>& v) {
    n = (int) v.size();
    tree.resize(2 * n);
    for (int i = n - 1; i > 0; i--) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }

  // Single position modificaion.
  void modify(int p, int val) {
    for (tree[p += n] = val; p > 1; p /= 2) {
      tree[p / 2] = tree[p] + tree[p ^ 1];
    }
  }

  void modify(int l, int r, int val) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) tree[l++] += val;
      if (r & 1) tree[--r] += val;
    }
  }

  // Sum over interval [l, r)
  int get(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) ans += tree[l++];
      if (r & 1) ans += tree[--r];
    }
    return ans;
  }

  int get(int p) {
    int ans = 0;
    for (p += n; p > 0; p /= 2) {
      ans += tree[p];
    }
    return ans;
  }
};

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
