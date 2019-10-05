#include<bits/stdc++.h>
using namespace std;

ll mi;
void solve(vi red, vi blue, ll path) {
  // trace(mi, path);
  // pvi(red);
  // pvi(blue);
  int n = sz(red); 
  if (n == 1) {
    mi = min(mi, path);
    return;
  }
  
  fori (i, 0, n) {
    fori (j, i + 1, n) {
      int a = red[i] ^ blue[j];
      int b = red[j] ^ blue[i];
      // trace(i, j, a, b, n);
      vi dummy_red = red;
      vi dummy_blue = blue;
      dummy_red.erase(dummy_red.begin() + i);
      dummy_blue.erase(dummy_blue.begin() + i);
      solve(dummy_red, dummy_blue, path + (a < b ? a : b));

      dummy_red = red;
      dummy_blue = blue;
      dummy_red.erase(dummy_red.begin() + j);
      dummy_blue.erase(dummy_blue.begin() + j);
      solve(dummy_red, dummy_blue, path + (a < b ? a : b));
    }
  }
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    vi red, blue;
    int n; cin >> n;
    fori (j, 0, n) {
      int a; cin >> a;
      red.pb(a);
    }
    fori (j, 0, n) {
      int a; cin >> a;
      blue.pb(a);
    }
    mi = inf;
    solve(red, blue, 0);
    output(i, mi);
  }

  return 0;
}
