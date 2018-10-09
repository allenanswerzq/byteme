#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int titleToNumber(string ss) {
    int res = 0;
    for (int i = 0; i < sz(ss); i++) {
      res = res * 26 + ss[i] - 'A' + 1;
    }
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
