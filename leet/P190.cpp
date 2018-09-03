#include<bits/stdc++.h>

using namespace std;

// Accepted
uint32_t reverseBits(uint32_t n) {
  uint32_t r = 0;        
  for (int i=0; i<32; ++i) {
  uint32_t y = (n >> i) & 1;
  r = r | (y << 31 - i);
  }
  return r;
}

int main(int argc, char** argv) {
  cout << reverseBits(43261596) << endl;
  return 0;
}
