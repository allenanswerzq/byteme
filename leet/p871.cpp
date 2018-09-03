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


class Solution {
public:
  int minRefuelStops(int target, int startFuel, vvi& aa) {
  int n = sz(aa);
  int d = startFuel;
  int res = 0;
  int k = 0;
  multiset<int> mst;
  while (d < target) {
  while (k < n && aa[k][0] <= d) {
  mst.insert(aa[k][1]);
  ++k;
  }
  if (sz(mst) == 0) return -1;
  d += *(prev(mst.end()));
  mst.erase(prev(mst.end()));
  ++res;
  } 
  return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p871-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
