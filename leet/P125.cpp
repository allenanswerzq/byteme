#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

bool isPalindrome(string s) {
  int lo=0, hi=s.size()-1;
  while (lo < hi) {
  while (!isalnum(s[lo])) ++lo;   // isalnum all digits and letters
  while (!isalnum(s[hi])) --hi;   // isalpha all letters no digits
  if (lo<hi && tolower(s[lo])!=tolower(s[hi])) return false;
  ++lo;
  --hi;
  }
  return true;
}

int main(int argc, char** argv) {
  return 0;
}
