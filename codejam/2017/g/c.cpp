#include<bits/stdc++.h>
using namespace std;

vvl mat;
ll samll(int lo, int hi) {
  // trace(lo, hi);
  if (lo == hi) return 0;
  // pvi(mat[0]);
  ll res = 0;
  fori (i, lo + 1, hi + 1) {
    res = max(res, samll(lo, i - 1) + samll(i, hi));
  }

  ll mi = inf;
  fori (i, lo, hi + 1)
    mi = min(mat[0][i], mi);
  // trace(lo, hi, mi, res);
  return mi + res;
}

const int maxn = 41;
ll dp[maxn][maxn][maxn][maxn];
void compute_min() {
  mst(dp, 0);
  int m, n;
  m = sz(mat), n = sz(mat[0]);
  trace(m, n);
  fori (i, 0, m) {
    fori (j, 0, n) {
      fori (k, i, m) {
        fori (h, j, n) {
          ll mi = mat[k][h];
          if (k - i > 0) mi = min(mi, dp[i][j][k-1][h]);
          if (h - j > 0) mi = min(mi, dp[i][j][k][h-1]);
          dp[i][j][k][h] = mi;
        }
      } 
    }
  }
  trace("compute_min");
}

// TODO: Still not work for large data.
ll large(int lo, int hi, int tp, int dn) {
  if (lo > hi || tp > dn) return 0;
  if (lo == hi && tp == dn) return 0;
  ll res = 0;
  fori (i, lo, hi)
    res = max(res, large(lo, i, tp, dn) + 
                   large(i + 1, hi, tp, dn));
  fori (i, tp, dn)
    res = max(res, large(lo, hi, tp, i) +
                   large(lo, hi, i + 1, dn));
  ll mi = dp[lo][tp][hi][dn];
  // ll mi = inf;
  // fori (i, lo, hi + 1)
  //   fori (j, tp, dn + 1) {
  //     mi = min(mi, mat[i][j]);
  //   }
  trace(lo, tp, hi, dn, mi, res);
  return res + mi; 
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    mat.clear();
    int n, m; cin >> n >> m;
    fori (i, 0, n) {
      vl tmp;
      fori (j, 0, m) {
        ll a; cin >> a;
        tmp.pb(a);
      } 
      mat.pb(tmp);
    } 
    // int r = solve_small(0, m - 1);
    compute_min();
    ll r = large(0, n-1, 0, m-1);
    output(i, r);
  }

  return 0;
}
