#include<bits/stdc++.h>
using namespace std;

bool check(ll inp) {
  if (inp % 9 == 0) return 0;
  string str = to_string(inp);
  fori (i, 0, sz(str))
    if (str[i] == '9')
      return 0;
  return 1; 
}

ll solve(ll l, ll r) {
  ll res = 0;
  forli (i, l, r + 1) {
    if (check(i))
      res++;
  }
  return res;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 0, t) {
    ll l, r; 
    cin >> l; cin >> r;
    ll a = solve(l, r);
    output(i + 1, a); 
  }

  return 0;
}
