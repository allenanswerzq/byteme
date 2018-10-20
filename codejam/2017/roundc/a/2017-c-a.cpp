#include<bits/stdc++.h>
using namespace std;

string solve() {
  string inp;
  cin >> inp;
  if (sz(inp) & 1) return "AMBIGUOUS";
  int n = sz(inp);
  vi enc(n + 1, 0), dec(n + 1, 0);
  fori (i, 1, n + 1)
    enc[i] = inp[i - 1] - 'A'; 

  dec[2] = enc[1];
  dec[n - 1] = enc[n];
  for (int i = 4; i <= n; i += 2) {
    // enc[i] = (dec[i-1] + dec[i + 1]) % 26
    dec[i] = (enc[i - 1] - dec[i - 2] + 26) % 26;
  }

  for (int i = n-3; i >= 1; --i) {
    dec[i] = (enc[i + 1] - dec[i + 2] + 26) % 26;
  }
  
  // pvi(enc);
  // pvi(dec);

  string res = "";
  fori (i, 1, n + 1)
    res += dec[i] + 'A';
  return res; 
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 1, t + 1) {
    string r = solve();
    output(i, r); 
  }

  return 0;
}
