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

  freopen("2018-roundb-a-small.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 0, t) {
    ll l, r; 
    cin >> l; cin >> r;
    ll a = solve(l, r);
    output(i + 1, a); 
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
