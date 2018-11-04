#include<bits/stdc++.h>
using namespace std;

bool helper(int x) {
  int y = x;
  while (x) {
    int t = x % 10;
    if(y % t) return false;
    x /= 10;
  }
  return x==0 ? false: true;
}

vi selfDividingNumbers(int left, int right) {
  vi ret;
  for (int i = left; i <= right; ++i)
    if (helper(i)) ret.push_back(i);
  return ret;
}
