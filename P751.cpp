#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl

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