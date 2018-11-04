#include<bits/stdc++.h>
using namespace std;

// TLE 218/302 tests passed
// Naive idea
int monotoneIncreasingDigits(int N) {
  for (int i=N; i>=0; --i) {
    int x = i % 10;
    int y = i / 10;
    while (x && y) {
      int t = y % 10;
      if (t > x) break;
      x = t; y /= 10;
    }
    if (y == 0) return i;
  }
  return 0;
}

// Idea: first, find a base nubmer that nearest N and also each bits are same.
// for example (222), Literally change every bits in that number to make
// it more close to N
int monotoneIncreasingDigits(int N) {
  vector<int> bits;
  for (int t = N; t; t /= 10) bits.push_back(t % 10);
  int n = bits.size();
  int ret = 0, pre = 0;
  for (int i = 0; i < n; ++i) for (int k = 9; k >= pre; --k) {
    int cur = ret;
    for (int j = i; j < n; ++j) cur = cur * 10 + k;
    if (cur <= N) {
      ret = ret * 10 +k;
      pre = k;
      break;
    }
  }
  return ret;
}

int monotoneIncreasingDigits(int N) {
  int base = 1, base2 = 1;
  for (int i = 0; i < 9; ++i) {
    base2 += base * 10;
    base = base * 10;
  }
  int pre = 0, ret = 0;
  while(base2 > 0) {
    for (int k = 9; k >= pre; --k) {
      ll cur = ret + base2 * k
      if (cur <= N) {
        ret += base * k;
        pre = k;
        break;
      }
    }
    base2 /= 10;
    base /= 10;
  }
  return ret;
}
