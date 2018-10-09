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


char go_small(ll k) {
  string s1 = "0";
  while (sz(s1) < k) {
    string s2 = s1;
    reverse(all(s2));
    fori (i, 0, sz(s2))
      if (s2[i] == '0') s2[i] = '1';
      else s2[i] = '0';
    s1 = s1 + "0" + s2;
  } 
  return (char)s1[k - 1];
}

ll cal(ll n) {
  ll res = 1;
  while (--n) {
    res = 2 * res + 1;
  }
  return res;
}

// TODO
char go_large(ll n, ll k) {
  if (n == 1) return '0';
  ll sn = cal(n);
  ll half = (sn + 1) / 2;
  if (k == half)
    return '0';
  else if (k < half)
    return go_large(n - 1, k);
  else 
    return go_large(n - 1, sn + 1 - k);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("in.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 0, t) {
    ll k; cin >> k;
    // char r = go_small(k);
    char r = go_large(64, k);
    cout << "Case #" << i + 1 << ": " << r << endl;
  } 

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
