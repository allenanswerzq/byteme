#include<bits/stdc++.h>
using namespace std;

// (100a+10b+c)%9 = (a+99a+b+9b+c)%9 = (a+b+c)%9
class Solution {
public:
  int addDigits(int aa) {
    if (aa == 0) return 0;        
    return aa % 9 == 0 ? 9 : aa % 9;
  }
};

int main(int argc, char** argv) {
  return 0;
}