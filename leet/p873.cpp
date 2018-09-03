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
  int lenLongestFibSubseq(vector<int>& aa) {
  int n = sz(aa);
  uset<int> st;
  fora (a, aa) st.insert(a);
  int res = 0;
  fori (i, 0, n) {
  fori (j, i+1, n) {
  int tmp = 2;
  int one = aa[i], two = aa[j];
  while (st.count(one + two)) {
    ++tmp;
    int three = one + two;
    one = two; 
    two = three;
  }
  if (tmp > 2) res = max(res, tmp);
  }
  }
  return res;
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p873-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  // vi aa = {1,2,3,4,5,6,7,8};
  // vi aa = {1,3,7,11,12,14,18};
  vi aa = {2,4,5,6,7,8,11,13,14,15,21,22,34};
  cout << go.lenLongestFibSubseq(aa);


  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
