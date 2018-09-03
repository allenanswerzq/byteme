#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef long long int64;
string to_ip(int64 x, int step) {
  vector<int> a(4);
  a[3] = x & 255; x >>= 8;
  a[2] = x & 255; x >>= 8;
  a[1] = x & 255; x >>= 8;
  a[0] = x;
  int len = 33;
  while (step) {
    step /= 2;
    --len;
  }
  stringstream ss;
  ss << a[0] << "." << a[1] << "." << a[2] << "." << a[3] << "/" << len;
  return ss.str();
}

vector<string> ipToCIDR(string ip, int range) {
  vector<string> ret;
  int64 x = 0;
  int a[4];
  istringstream in(ip);
  sscanf(ip.c_str(), "%c.%c.%c.%c", &a[0], &a[1], &a[2], &a[3]);
  x |= a[0]; x <<= 8;
  x |= a[1]; x <<= 8;
  x |= a[2]; x <<= 8;
  x |= a[3];
  while (range) {
  // possible steps values are 1, 2, 4, 8, ...
  int steps = x & -x; //x & (-x) will return rightmost 1. 011(1)-->steps-->1000 10(1)0-->steps-->1(1)00
  while (steps > range) steps /= 2;
  ret.push_back(to_ip(x, steps));
  x += steps;
  range -= steps;
  }
  return ret;
}
