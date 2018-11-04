#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string to_ip(ll x, int step) {
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
  ll x = 0;
  int a[4];
  istringstream in(ip);
  sscanf(ip.c_str(), "%c.%c.%c.%c", &a[0], &a[1], &a[2], &a[3]);
  x |= a[0]; x <<= 8;
  x |= a[1]; x <<= 8;
  x |= a[2]; x <<= 8;
  x |= a[3];
  while (range) {
    int steps = x & -x;
    while (steps > range) steps /= 2;
    ret.push_back(to_ip(x, steps));
    x += steps;
    range -= steps;
  }
  return ret;
}
