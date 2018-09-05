#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string s) {
  int n = s.size()-1;
  int res = 0;
  for (auto x : s) {
    res += (pow(26,n) * (toupper(x)-'A'+1));
    --n;
  }
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
