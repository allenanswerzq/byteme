#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int compareVersion(string version1, string version2) {
    istringstream iss1(version1);
    istringstream iss2(version2);
    while (1) {
      char c;
      int a = -1, b = -1; 
      iss1 >> a >> c;
      iss2 >> b >> c; 
      trace(a, b);
      if (a == -1 && b == -1) break;
      if (a == -1) a = 0;
      if (b == -1) b = 0;
      if (a != b) return a > b ? 1 : -1;
    }
    return 0;
  }
};


int main() {
  return 0;
}
