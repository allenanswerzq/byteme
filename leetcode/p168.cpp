#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string ret = "";
    while (n) {
      n--;
      ret = char(n % 26 + 'A') + ret;
      n = n / 26;
    }
    return ret;
  }

};

void test(int n) {
  Solution go;
  auto r = go.convertToTitle(n);
  cout << r << '\n';
}

int main(int argc, char** argv) {
  test(1);
  test(26);
  test(27);
  test(28);
  test(701);
  return 0;
}
