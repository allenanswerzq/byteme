#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int findParenthesis(string aa, int k) {
  int cnt = 0;
  int n = aa.size();
  for (int i=k+1; i<n; ++i) {
    if (aa[i] == '(') 
      ++cnt;
    else if (aa[i] == ')') {
      if (cnt == 0) 
        return i;
      else 
        --cnt;
    }
  }
  return -1;
}

int main() {
  string msg = "Sometimes (when I nest them (my parentheticals) \
    too much (like this (and this))) they get confusing.";
  cout << findParenthesis(msg, 10);
  return 0;
}
