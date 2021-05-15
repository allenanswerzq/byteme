/* created   : 2020-12-21 22:58:41
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll INF = (ll)1e18 + 7;

template <class T>
struct Matrix {
  vector<vector<T>> v_;
  int n_;
  int m_;

  Matrix(int n, int m) : n_(n), m_(m) {
    v_.resize(n_, vector<T>(m_));
  }

  Matrix(int n, int m, T x) : n_(n), m_(m) {
    v_.resize(n_, vector<T>(m_, x));
  }

  Matrix(const Matrix& o) {
    *this = o;
  }

  vector<T>& operator[](int r) {
    assert(0 <= r && r < n_);
    return v_[r];
  }

  void operator=(const Matrix& o) {
    v_ = o.v_;
    n_ = o.n_;
    m_ = o.m_;
  }

  void debug() {
    trace(v_);
  }

  Matrix& operator*=(const Matrix& o) {
    assert(m_ == o.n_);
    Matrix ans(n_, o.m_);
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < o.m_; j++) {
        T cur = INF;
        for (int k = 0; k < m_; k++) {
          cur = min(cur, v_[i][k] + o.v_[k][j]);
        }
        ans[i][j] = cur;
      }
    }
    *this = ans;
    return *this;
  }

  Matrix operator^(ll t) {
    assert(t >= 0);
    assert(n_ == m_);
    Matrix ans = *this;
    Matrix a(*this);
    while (t) {
      if (t & 1) ans *= a;
      a *= a;
      t >>= 1;
    }
    return ans;
  }

  friend Matrix operator*(const Matrix& a, const Matrix& b) { return Matrix(a) *= b; }
};

void solve() {
  trace(INF);
  int N, M, K; cin >> N >> M >> K;
  Matrix<ll> mat(N, N, INF);
  for (int i = 0; i < M; i++) {
    int u, v, c; cin >> u >> v >> c;
    u--, v--;
    mat[u][v] = min(mat[u][v], (ll)c);
  }
  mat.debug();
  mat = mat ^ (K - 1);
  mat.debug();
  trace(INF);
  cout << (mat[0][N - 1] == INF ? -1 : mat[0][N - 1]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}

