#include<bits/stdc++.h>
using namespace std;

// A strobogrammatic number is a number that looks the same 
// when rotated 180 degrees (looked at upside down).
// Find all strobogrammatic numbers that are of length = n.
// For example,
// Given n = 2, return ["11","69","88","96"].
// Hint:
// Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.

vector<string> findStrobogrammatic(int n) {
  vector<string> ret;
  vector<string> template = {"00", "11", "88", "96", "69"};
  ret = n & 1 ? {"0", "1", "8"} : {""}; 
  while (n > 1) {
  // Each time add two characters on both sides of ret string
  n -= 2;  
  vector<string> tmp;
  for (auto s : ret)
  for (int i=0; i < tmplate.size(); ++i)
  tmp.push_back(template[i][0] + s + tmplate[i][1]); 
  ret = tmp;
  }
  return ret;
}

int main(int argc, char** argv) {
  return 0;
}
