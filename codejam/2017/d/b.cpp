#include<bits/stdc++.h>
using namespace std;

const int size = 220;
ll mat[size][size];
ll sum[size][size];

void build(int n, int a, int b, int c, 
           int d, int e1, int e2, int f) {

  ll x1, y1, r1, s1;
  x1 = a, y1 = b; 
  r1 = 0, s1 = 0;
  vi aa(n + 1, 0), bb(n + 1, 0);
  aa[1] = x1; 
  bb[1] = y1;
  fori (i, 2, n + 1) {
    ll x = (c * x1 + d * y1 + e1 ) % f;
    ll y = (d * x1 + c * y1 + e2 ) % f;
    ll r = (c * r1 + d * s1 + e1 ) % 2;
    ll s = (d * r1 + c * s1 + e2 ) % 2;
    x1 = x, y1 = y;
    r1 = r, s1 = s;
    ll z = r & 1 ? -x : x;
    ll g = s & 1 ? -y : y;
    aa[i] = z;
    bb[i] = g;
  }

  // pvi(aa);
  // pvi(bb);

  mst(mat, 0);
  fori (i, 1, n + 1) {
    fori (j, 1, n + 1) {
      mat[i][j] = aa[i] * bb[j]; 
    }
  }
}


ll get_sum(int a, int b, int c, int d) {
  return sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
}

ll solve() {
  int n, kk, a, b, c, d, e1, e2, f;
  cin >> n >> kk >> a >> b >> c >> d >> e1 >> e2 >> f;
  // trace(n, kk, a, b, c, d, e1, e2, f);
  build(n, a, b, c, d, e1, e2, f);
  mst(sum, 0);
  fori (i, 1, n + 1) {
    fori (j, 1, n + 1) {
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i][j];
    }
  } 

  priority_queue<ll, vl, greater<ll>> pq;
  int cnt = 0;
  fori (a, 1, n + 1) {
    fori (b, 1, n + 1) {
      fori (c, a, n + 1) {
        fori (d, b, n + 1) {
          ll curr_sum = get_sum(a, b, c, d);
          if (cnt < kk) {
            pq.push(curr_sum);
            ++cnt;
          } else {
            if (curr_sum > pq.top()) {
              pq.pop();
              pq.push(curr_sum); 
            }
          }
        }
      }
    }
  }
  return pq.top();
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 1, t + 1) {
    ll r = solve();
    output(i, r);
  } 
  
  return 0;
}
