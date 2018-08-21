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


// TODO: still not work for large data cause of overflow.
ll check(ll ones, ll goal, ll base) {
  ull cur = 1;
  ull ans = 0;
  fori (i, 0, ones) {
    ans = ans + cur;
    // Note: overflow might occur here.
    cur = cur * base;
    // trace(ans, cur);
    if (ans > goal) return 1;
  }
  if (ans > goal) return 1;
  if (ans < goal) return -1;
  return 0;
}

ll solve() {
  ll inp; cin >> inp;
  ll ones = 62;
  ford (i, ones, 1) {
    ll lo = 2, hi = inp - 1; 
    while (lo <= hi) {
      ll mid = lo + (hi - lo) / 2;
      ll r = check(i, inp, mid);
      if (r == 0) return mid;
      else if (r == 1) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
  }
  return -1;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-p2-c-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  t = 1;
  fori (i, 1, t + 1) {
    ll r = solve();
    output(i, r);  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
