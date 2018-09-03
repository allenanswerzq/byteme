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

vs missingRange(vi& aa, int lo, int hi) {
  vs res;
  aa.insert(aa.begin(), lo - 1);
  aa.insert(aa.end(), hi + 1);
  fori (i, 0, sz(aa) - 1) {
  int ss = aa[i], tt = aa[i+1]; 
  if (tt - ss + 1 == 3) {
    res.pb(to_string(ss + 1));
  } else if (tt - ss + 1 > 3) {
    res.pb(to_string(ss + 1) + "->" + to_string(tt - 1));
  }
  }
  return res;
}


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p163-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  vi aa = {1};
  vs res = missingRange(aa, 0, 99); 
  pvi(res);  

  res.clear();
  aa = {};
  res = missingRange(aa, 0, 99);
  pvi(res);

  aa = {0, 1, 3, 50, 75};
  res = missingRange(aa, 0, 99);
  pvi(res);

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
