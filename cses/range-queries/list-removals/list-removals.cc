/* created   : 2020-11-28 19:14:35
 * accepted  : 2020-11-28 20:48:28
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <class T>
class Bit {
 public:
  Bit(int n) : n_(n) { t_.resize(n + 1); }

  void add(int x, int d) {
    for (; x <= n_; x += lowbit(x)) {
      t_[x] += d;
    }
  }

  // Query sum of interval [1...x].
  T query(int x) {
    T ans = 0;
    for (; x > 0; x -= lowbit(x)) {
      ans += t_[x];
    }
    return ans;
  }

  T query(int l, int r) { return query(r) - query(l - 1); }

 private:
  int lowbit(int x) { return x & -x; }
  int n_;
  vector<T> t_;
};

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  Bit<int> use(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    use.add(i + 1, 1);
  }
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    int lo = -1;
    int hi = N;
    while (lo + 1 < hi) {
      int md = (lo + hi) >> 1;
      if (use.query(md + 1) >= x) {
        hi = md;
      }
      else {
        lo = md;
      }
    }
    cout << A[hi] << (i == N - 1 ? '\n' : ' ');
    use.add(hi + 1, -1);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
