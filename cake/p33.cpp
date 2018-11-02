#include<bits/stdc++.h>
using namespace std;

int find(vector<int> v) {
  int n = sz(v);
  int a = 0, b = 0;
  fori (i, 0, n-1) a ^= i;
  fora (x, v) b ^= x;
  return a ^ b;
}

int main() {
  return 0;
}
