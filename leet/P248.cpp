#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
// For example,
// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

void dfs(string low, string high, vector<char>& buf, int lo, int hi, int& count, vector<string>&path, pair<int,int> pairs) {
  if (lo > hi) {
    // Construct string of length hi-lo+1 is done 
    // Now it's time to check validity
    string number(buf.begin(), buf.end());
    if (stoi(number)<stoi(low) || stoi(number)>stoi(high))
      return;
    count++; 
  }
  // Core idea is that construct all possible string according to range length
  // and see if it in the range of low and high
  for (auto p: pairs) {
    // target string we want to get: lo ..... hi
    // fill two side characters so this string will be a strobogrammatic number string 
    buf[lo] = p.first;
    buf[hi] = p.second;

    if (buf.size()>1 && buf[0]=='0') // first character of a valid number should not be 0
      continue; 

          continue;
    // recusively construct other characters
    dfs(low, high, buf, lo+1, hi-1, count, path, pairs);
  }
}

int strobogrammaticInRange(string low, string high) {
  pair<int, int> pairs = { {"0", "0"}, {"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"} }; 
  int count = 0;
  vector<string> path;
  for (int len=low.size(); len<=high.size(); len++) {
    vector<char> buf(len);
    dfs(low, high, buf, 0, len-1, count, path, pairs);
  }
  return count;
}
