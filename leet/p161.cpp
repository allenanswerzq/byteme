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

class Solution {
public:
  bool isOneEditDistance(string ss, string tt) {
  int m = sz(ss), n = sz(tt);
  fori (i, 0, min(m, n)) {
  if (ss[i] != tt[i]) {
  if (m == n) return ss.substr(i) == tt.substr(i); // 
  else if (m > n) return ss.substr(i + 1) == tt.substr(i);
  else return ss.substr(i) == tt.substr(i + 1);
  } 
  }
  return abs(m - n) == 1;
  }
};



int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p161-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
