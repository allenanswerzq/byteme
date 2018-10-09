#include<bits/stdc++.h>
using namespace std;




template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


// ll solve() {
//   string a; cin >> a;
//   int n = sz(a);

//   ll lo, hi; cin >> lo >> hi;
//   ll res = 0;
//   fori (i, lo, hi + 1) {
//     if (a[(i - 1) % n] == 'B')
//       ++res; 
//   }
//   return res;
// }

const int size = 120;
ll aa[size];
ll bb[size]; 
ll solve() {
  string s; cin >> s;
  ll n = sz(s);
  ll lo, hi; cin >> lo >> hi;

  aa[0] = s[0] == 'B' ? 1 : 0;
  fori (i, 1, n) {
    if (s[i] == 'B') aa[i] = aa[i - 1] + 1;
    else aa[i] = aa[i - 1];
  }

  bb[n - 1] = s[n - 1] == 'B' ? 1 : 0;
  ford (i, n - 2, -1 ) {
    if (s[i] == 'B') bb[i] = bb[i + 1] + 1;
    else bb[i] = bb[i + 1];
  }

  ll len = hi - lo + 1;
  ll ix = (lo - 1) % n;
  ll t = (len - (n - ix)) / n;
  ll x = (len - (n - ix) - 1) % n;
  // trace(len, ix, t, x);
  return (bb[ix] + (t * aa[n - 1]) + (x == n - 1 ? 0 : aa[x]));
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-p2-a-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
    ll r = solve();
    output(i, r);  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
