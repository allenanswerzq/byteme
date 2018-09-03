#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

string inp;
ll parse(int idx, int len) {
  if (idx + len > sz(inp)) return -1; 
  if (len >= 2 && inp[idx] == '0') return -1;

  ll res = stoll(inp.substr(idx, len));
  if (res > INT_MAX) return -1;

  return res;
}

class Solution {
public:
  vector<int> splitIntoFibonacci(string S) {      
  inp = S;
  int n = sz(inp);
  fori(len0, 1, 11) {
    ll a0 = parse(0, len0);
    if (a0 == -1) break;

    fori(len1, 1, 11) {
    ll a1 = parse(len0, len1);
    if (a1 == -1) break;

    bool ok = true;
    ll x0 = a0, x1 = a1;
    int cur = len0 + len1;
    vi res;
    res.pb(x0);
    res.pb(x1);
    while (cur < n) {
      ll x2 = x0 + x1; 
      int len3 = sz(to_string(x2));
      int y = parse(cur, len3);
      if (x2 == y) {
      res.pb(x2);
      x0 = x1;
      x1 = x2;
      cur += len3;
      } else {
      ok = false;
      break;
      }
    }
    if (ok && sz(res) >= 3)
      return res;
    }
  }
  return {};
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  Solution go;
  go.splitIntoFibonacci("123456789");
  return 0;
}
