#include<bits/stdc++.h>
using namespace std;

bool check(ll inp) {
  string s = to_string(inp);
  // trace(s);
  fori (i, 0, sz(s))
    if ((s[i]-'0') % 2)
      return 0;
  return 1;
}

ll solve(ll inp) {
  if (check(inp)) return 0; 
  int res = 0;
  fori (i, 1, inf)
    if (check(inp + i)) {
      // trace(inp + 1);
      res = i;
      break;
    }

  ford (i, -1, nnf)
    if (check(inp + i)) {
      res = min(res, abs(i));
      break;
    }
  return res;
}

// TODO large dataset.

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 0, t) {
    ll a; cin >> a; 
    ll r = solve(a);
    cout << "Case #" << i + 1 << ": " << r << endl;
  }

  return 0;
}
