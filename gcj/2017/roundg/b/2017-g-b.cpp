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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-g-b-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();

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

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
