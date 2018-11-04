#include<bits/stdc++.h>
using namespace std;

string build(char x, char y, ll n, ll a, ll b, 
             ll c, ll d) {
  string res = "";
  res += x;
  res += y;
  ll x1 = x, x2 = y;
  fori (i, 3, n + 1) {
    ll xi = (a * x2 + b * x1 + c) % d;
    char c = (char)(97 + xi % 26);
    x1 = x2;
    x2 = xi;
    // trace(c, x1, x2);
    res += c;
  } 
  return res;
}

bool check(string a, string b) {
  int m, n;
  m = sz(a), n = sz(b);
  if (m != n) return 0;
  if (!(a[0]==b[0] && a[m-1]==b[n-1])) return 0;
  int dp[26] = {0};

  fori (i, 1, m-1) {
    dp[a[i] - 'a']++;
    dp[b[i] - 'a']--; 
  }

  fori (i, 0, 26) 
    if (dp[i])
      return 0;
  return 1;
}

vs inp;
int solve(string strs) {
  int res = 0;
  int n = sz(strs);
  fora (a, inp) {
    fori (i, 0, n) {
      if (check(strs.substr(i, sz(a)), a)) {
        res++;
        break;
      }
    }
  }
  return res;
}

int main() {
 
  int t; cin >> t;
  fori (i, 0, t) {
    inp.clear();
    int k; cin >> k;
    fori (i, 0, k) {
      string a; cin >> a;
      inp.pb(a);
    } 
    char x1, x2;
    ll n, a, b, c, d;
    cin >> x1 >> x2 >> n >> a >> b >> c >> d;
    string strs = build(x1, x2, n, a, b, c, d); 
    // trace(strs);
    // pvi(inp);
    int r = solve(strs);
    cout << "Case #" << i + 1 << ": " << r << endl;
  }

  return 0;
}
