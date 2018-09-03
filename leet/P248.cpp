#include<bits/stdc++.h>
using namespace std;

// A strobogrammatic number is a number that looks the same 
// when rotated 180 degrees (looked at upside down).
// Write a function to count the total strobogrammatic numbers 
// that exist in the range of low <= num <= high.
// For example,
// Given low = "50", high = "100", return 3. 
// Because 69, 88, and 96 are three strobogrammatic numbers.

#define pii pair<int, int>

int count;
string low;
string high;
pii pairs;

void dfs(vector<char>& buf, int lo, int hi) {
  if (lo > hi) {
  // Construct string of length hi-lo+1 is done 
  // Now it's time to check validity
  string number(buf.begin(), buf.end());
  if (stoi(number) < stoi(low) || stoi(number) > stoi(high))
  return;
  count++; 
  }

  // Core idea is that construct all possible string according to range length
  // and see if it in the range of low and high
  for (auto p : pairs) {
  // Target string we want to get: lo ..... hi
  // Fill two sides characters so this string will be a strobogrammatic number string 
  buf[lo] = p.first;
  buf[hi] = p.second;
  
  // First character of a valid number should not be 0
  if (buf.size()>1 && buf[0]=='0') 
  continue; 

  // Recusively construct other characters
  dfs(buf, lo+1, hi-1, count);
  }
}

int strobogrammaticInRange(string aa, string bb) {
  count = 0;
  low = aa;
  hight = bb;
  pairs = {{"0", "0"}, {"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}}; 
  for (int len = sz(low); len <= sz(high); len++) {
  vector<char> buf(len);
  dfs(buf, 0, len-1, count);
  }
  return count;
}

int main(int argc, char** argv) {
  return 0;
}
