#include<bits/stdc++.h>using namespace std;

class Solution {
public:
  int romanToInt(string ss) {
    string syms[] = {"I", "IV", "V", "IX", "X", "XL", 
                     "L", "XC", "C", "CD", "D", "CM", "M"};
    int value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int ret = 0;
    int k = 0;
    for (int i = 12; k < ss.size() && i >= 0; --i) {
      int t = syms[i].size();
      while (ss.substr(k, t) == syms[i]) {
        ret += value[i];
        k += t;
      }
    }
    return ret;
  }

  string intToRoman(int num) {
    string syms[] = {"I", "IV", "V", "IX", "X", "XL", "L", 
                     "XC", "C", "CD", "D", "CM", "M"};
    int value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string ret = "";
    for (int i = 12; num != 0; --i)
      while (num >= value[i]) {
        ret += syms[i];
        num -= value[i];
      }
    return ret;
  }
};

void test(int inp) {
  Solution go;
  string x = go.intToRoman(inp);
  int y = go.romanToInt(x);
  trace(inp, x, y);
}

int main(){
  test(3);
  test(1904);
  test(1954);
  test(1990);
  test(2014);
  return 0;
}
