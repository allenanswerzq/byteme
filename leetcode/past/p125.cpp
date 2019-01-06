#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(string ss) {
    int lo = 0, hi = ss.size() - 1;
    while (lo < hi) {
      while (!isalnum(ss[lo])) ++lo;
      while (!isalnum(ss[hi])) --hi;
      if (lo < hi && tolower(ss[lo++]) != tolower(ss[hi--])) 
        return false;
    }
    return true;
  }
};

int main() {
  return 0;
}
