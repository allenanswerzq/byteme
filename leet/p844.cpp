#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

string strip(string inp) {
  int n = sz(inp);
  char stk[n];
  int k = 0;
  fori(i, 0, n) {
  if (inp[i] == '#') {
  if (k > 0)
  --k;
  } else {
  stk[k++] = inp[i];
  }
  } 

  string res = "";
  fori(i, 0, k)
  res += stk[i];
  return res;
}

class Solution {
public:
  bool backspaceCompare(string S, string T) {
  string a = strip(S);
  string b = strip(T);
  return a == b;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
