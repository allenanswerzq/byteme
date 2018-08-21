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


int findMin(vi& aa) {
  int lo=0, hi = sz(aa) - 1;
  while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (mid < hi && aa[mid] > aa[mid+1]) return aa[mid+1];
      if (mid > lo && aa[mid] < aa[mid-1]) return aa[mid];
      if (aa[mid] < aa[hi])
        hi = mid - 1;
      else
        lo = mid + 1; 
  }
  return aa[lo];
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p153-2-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
