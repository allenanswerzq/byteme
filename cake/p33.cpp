#include<bits/stdc++.h>
using namespace std;

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
