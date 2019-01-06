#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string addBinary(string aa, string bb) {
    string ss = "";
    int c = 0, i = aa.size() - 1, j = bb.size() - 1;
    while (i >= 0 || j >= 0 || c) {
      c += i >= 0 ? aa[i--] - '0': 0;
      c += j >= 0 ? bb[j--] - '0': 0;
      ss = char(c%2 + '0') + ss;
      c /= 2;
    }
    return ss;
  }
};


int main() {
  return 0;
}
