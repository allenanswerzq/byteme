#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int x) {
  return x * !(x & (x-1)) > 0;
  }
};

int main(int argc, char** argv) {
  return 0;
}
