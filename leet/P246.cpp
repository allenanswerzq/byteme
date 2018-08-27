#include<bits/stdc++.h>
using namespace std;

// A strobogrammatic number is a number that looks the same 
// when rotated 180 degrees (looked at upside down).
// Write a function to determine if a number is strobogrammatic. 
// The number is represented as a string.
// For example, the numbers "69", "88", and "818" are all strobogrammatic.

#define sz(x) (int)(x).size()

bool isStrobogrammatic(string aa) {
  unordered_map<char, char> mp{
    {'0': '0'},
    {'1': '1'},
    {'6': '9'}, 
    {'9': '6'}, 
    {'8': '8'} 
  };
  for (int i=0, r=sz(aa)-1; i < aa.size(), r >= 0; ++i, --r) {
    if (!mp.count(aa[i])) return 0;
    if (mp[aa[i]] != aa[r]) return 0;
  }
  return true;
}

int main(int argc, char** argv) {
  return 0;
}