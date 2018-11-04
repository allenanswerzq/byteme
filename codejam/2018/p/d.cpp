#include<bits/stdc++.h>
using namespace std;

vi inp;
vpii query;

vl solve_small() {
  vl res;
  res.clear();
  int n = sz(inp);
  fori (i, 0, n) {
    ll sum = 0;
    fori (j, i, n) {
      sum += inp[j]; 
      res.pb(sum);
    }
  } 

  sort(all(res));
  n = sz(res);
  ll dp[n + 1];
  mst(dp, 0);
  fori (i, 0, n)
    dp[i+1] = dp[i] + res[i];

  // pvi(res);
  // par(dp, n + 1);

  vl ans;
  ans.clear();
  fora (q, query) {
    if (q.se >= n) q.se = n;
    if (q.fi <= 1) q.fi = 1;
    // trace(q.se, q.fi, n);
    ll tmp = dp[q.se] - dp[q.fi-1];
    ans.pb(tmp);
  }
  return ans;
}

int main() {
 
  int t; cin >> t;
  fori (i, 0, t) {
    inp.clear();
    query.clear();
    int n, q;
    cin >> n; cin >> q;
    fori(j, 0, n) {
      int k; cin >> k;
      inp.pb(k);
    } 

    fori (j, 0, q) {
      int a, b;
      cin >> a; cin >> b;
      query.pb({a, b});
    }
    vl res = solve_small();
    cout << "Case #" << i + 1 << ":" << endl;
    fora (r, res)
      cout << r << endl; 
    // res.clear();
  }

  return 0;
}
