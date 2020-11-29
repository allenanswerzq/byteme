/* created   : 2020-11-29 20:15:34
 * accepted  : 2020-11-29 21:09:18
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

// Zero-index based
template <class T>
class Bit {
 public:
  Bit(int n, int m) : n_(n), m_(m) { t_.resize(n_ + 1, vector<T>(m_ + 1)); }

  void add(int x, int y, int d) {
    for (++x; x <= n_; x += lowbit(x)) {
      int y1 = y;
      for (++y1; y1 <= m_; y1 += lowbit(y1)) {
        t_[x][y1] += d;
      }
    }
  }

  // Query sum of interval [0...x].
  T query(int x, int y) {
    T ans = 0;
    for (++x; x > 0; x -= lowbit(x)) {
      int y1 = y;
      for (++y1; y1 > 0; y1 -= lowbit(y1)) {
        ans += t_[x][y1];
      }
    }
    return ans;
  }

  T query(int x1, int y1, int x2, int y2) {
    x1--, y1--;
    return query(x2, y2) - query(x1, y2) - query(x2, y1) + query(x1, y1);
  }

 private:
  int lowbit(int x) { return x & -x; }
  int n_, m_;
  vector<vector<T>> t_;
};

void solve() {
  int N, Q; cin >> N >> Q;
  Bit<int> bit(N, N);
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    for (int j = 0; j < N; j++) {
      if (s[j] == '*') {
        bit.add(i, j, 1);
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int y, x; cin >> y >> x;
      y--, x--;
      if (bit.query(y, x, y, x) == 1) {
        bit.add(y, x, -1);
      }
      else {
        bit.add(y, x, 1);
      }
    }
    else {
      int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
      y1--, x1--, y2--, x2--;
      cout << bit.query(y1, x1, y2, x2) << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
