#include<bits/stdc++.h>
using namespace std;

// TODO
vi inp;
ld solve(int k) {
  int n = sz(inp);
  ld pre = 0;
  fori (i, 0, n)
    pre += inp[i] * 1.0 / n; 

  if (k == 0) return pre;
  fori (i, 0, k) {
    ld cur = 0;
    fori (j, 0, n) {
      if (inp[j] >= pre)
        cur += inp[j] * 1.0 / n;
      else
        cur += pre / n;
    }
    pre = cur;
  }
  return pre;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(6);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 0, t) {
    inp.clear();
    int n, k;
    cin >> n; cin >> k;
    fori(j, 0, n) {
      int v; cin >> v;
      inp.pb(v);
    }
    ld r = solve(k);
    cout << "Case #" << i + 1 << ": " << r << endl;
  }
  
  return 0;
}
