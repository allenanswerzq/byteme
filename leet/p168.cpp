#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string ret = "";
    while (n) {
      ret = char((n - 1) % 26 + 'A') + ret;
      n = (n - 1) / 26;
    }
    return ret;
  }
};

int main(int argc, char** argv) {
  return 0;
}
