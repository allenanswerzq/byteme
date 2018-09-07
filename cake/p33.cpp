#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int find(vector<int> v) {
  int n = sz(v);
  int a=0, b=0;
  fori(i, 0, n-1)
    a ^= i;
  fora(x, v)
    b ^= x; 
  return a^b;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cout << find({0, 1, 2, 3, 3}) << '\n';
}
