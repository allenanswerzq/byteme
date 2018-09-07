#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void reverse(string& aa) {
  // Case
  if (aa == "") return "";
  int n = aa.size();
  int lo=0, hi=n-1;
  while (lo < hi) {
    swap(aa[lo], aa[hi]);
    ++lo;
    --hi;
  }
}

int main() {
  return 0;
}
